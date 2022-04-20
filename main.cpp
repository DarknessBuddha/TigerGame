#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"

#include <iostream>
#include <cctype>
#include <numeric>
using namespace std;

int main() {

    // 1. Create a deck of cards and shuffle it.
    // 2. Create two players, each one with 5 cards in their hand.
    // 3. Play five rounds. In each round:
    //    - Have computer deal a card from their hand.
    //    - Show human their hand of cards so that they can make a selection.
    //    - Have human deal their card. 
    //    - Determine who won the round and update points accordingly.
    //    - Print results for current round.
    // 4. Print final game results.  

    // initialize variables
    int totalRounds = 0;
    // vectors to keep track of scores and wins
    vector<int> humanScores, computerScores;
    vector<int> humanWins, computerWins;

    // game loop
    while(true){
        // initialize game
        ++totalRounds;
        humanScores.push_back(0);
        humanWins.push_back(0);
        computerScores.push_back(0);
        computerWins.push_back(0);

        string input; // variable to store input buffer

        // function to check if input is a number
        auto isInputANumber = [&input]()->bool{
            for(auto c: input){
                if(!isdigit(c)){
                    cout << "Input a number: ";
                    return false;
                }
            }
            return true;
        };

        int rounds = 5;

        // function to check if the number of round is valid
        auto isNumberOfRoundValid = [&input, &rounds]()->bool{
            rounds = stoi(input);
            if(rounds > 10){
                cout << "Input a number between 1 and 10: ";
                return false;
            }
            return true;
        };

        // make deck and shuffle it
        Deck deckOfCards;
        deckOfCards.shuffle();

        // introduction
        cout << "Welcome to TigerGame!\n";
        cout << "How many rounds?\n";

        // get and validate input
        getline(cin, input);
        while(!isInputANumber() || !isNumberOfRoundValid()){
            getline(cin, input);
        }
        
        // initialize the players
        Player computer{deckOfCards, rounds};
        Player human{deckOfCards, rounds};

        cout << "The deck was shuffled and each player has drawn " << rounds <<  " cards.\n\n";

        // game begins
        for(int i = 0; i < rounds; ++i){
            Card computerCard, humanCard; // variables to store cards

            // computer's turn
            cout << "Round " << i+1 << "\n-------\n";
            cout << "The computer plays: " << (computerCard = computer.hand.dealCard(0)).printCard() << "\n";

            // human's turn
            cout << "Your hand: " << human.hand.printHand() << "\n";
            cout << "Which card do you want to play? ";

            int position;
            // function to check if position is valid
            auto isPositionValid = [&position, &input, &human]()->bool{
                position = stoi(input)-1; // convert string to number
                if(position > human.hand.getHandSize()){
                    cout << "Input a number between 1 and " << human.hand.getHandSize() << ": ";
                    return false;
                }
                return true;
            };

            // get and validate input
            getline(cin, input);
            while(!isInputANumber() || !isPositionValid()){
                getline(cin, input);
            }

            cout << "You played: " << (humanCard = human.hand.dealCard(position)).printCard() << "\n";
            
            // check winner for the round
            if(computerCard.getValue() > humanCard.getValue()){
                cout << "The computer wins this round!\n";
                int score = computerCard.getValue() + humanCard.getValue();
                // update scores and wins
                computer.score += score;
                *(computerScores.end()-1) += score;
                *(computerWins.end()-1) += 1;
            }else if(humanCard.getValue() > computerCard.getValue()){
                cout << "You win this round!\n";
                int score = computerCard.getValue() + humanCard.getValue();
                // update scores and wins
                human.score += score;
                *(humanScores.end()-1) += score;
                *(humanWins.end()-1) += 1;
            }else{
                cout << "Tie!\n";
            }

            // print results for current round
            cout << "\nCurrent scores:\n";
            cout << "Human: " << human.score << "\n";
            cout << "Computer: " << computer.score <<"\n\n";
        }

        // print final results
        cout << "FINAL SCORE:\n";
        cout << "Human: " << human.score << "\n";
        cout << "Computer: " << computer.score <<"\n";

        if(human.score == computer.score) cout << "Tie Game!\n";
        else cout << "\n" << ((human.score > computer.score)? "Human": "Computer") << " has won!\n";

        // prompt to continue playing
        cout << "Type yes to continue playing: ";
        getline(cin, input);
        if(input.find("yes") == string::npos) break;
        cout << "\n";
    };
    
    // print summary
    cout << string(32, '-') << "\n";
    cout << "\nSummary\n";
    cout << "Total Rounds: " << totalRounds << "\n\n";
    
    // print summary of all games
    for(int i = 0; i < totalRounds; i++){
        cout << "Round " << i+1 << "\n";
        cout << "Computer Score: " << computerScores[i] << "\n";
        cout << "Human Score: " << humanScores[i] << "\n";
        cout << "Computer Wins: " << computerWins[i] << "\n";
        cout << "Human Wins: " << humanWins[i] << "\n\n";
    }
    
    // print total scores and wins
    cout << "All Rounds\n";
    cout << "Computer Total Score: " << accumulate(computerScores.begin(), computerScores.end(), 0) << "\n";
    cout << "Human Total Score: " << accumulate(humanScores.begin(), humanScores.end(), 0) << "\n";
    cout << "Computer Total Wins: " << accumulate(computerWins.begin(), computerWins.end(), 0) << "\n";
    cout << "Human Total Wins: " << accumulate(humanWins.begin(), humanWins.end(), 0) << "\n";
    
  return 0;
}
