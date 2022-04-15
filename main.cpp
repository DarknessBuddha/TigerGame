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

    int totalRounds = 0;
    
    std::vector<int> humanScores, computerScores;
    std::vector<int> humanWins, computerWins;

    while(true){
        ++totalRounds;
        humanScores.push_back(0);
        humanWins.push_back(0);
        computerScores.push_back(0);
        computerWins.push_back(0);

        std::string input;
        auto isInputANumber = [&input]()->bool{
            for(auto c: input){
                if(!isdigit(c)){
                std::cout << "Input a number: ";
                return false;
                }
            }
            return true;
        };

        int rounds = 5;
        auto isNumberOfRoundValid = [&input, &rounds]()->bool{
            rounds = std::stoi(input);
            if(rounds > 10){
                std::cout << "Input a number between 1 and 10: ";
                return false;
            }
            return true;
        };

        Deck deckOfCards;
        deckOfCards.shuffle();

        std::cout << "Welcome to TigerGame!\n";
        std::cout << "How many rounds?\n";

        std::getline(cin, input);
        while(!isInputANumber() || !isNumberOfRoundValid()){
            std::getline(cin, input);
        }
        
        Player computer{deckOfCards, rounds};
        Player human{deckOfCards, rounds};

        std::cout << "The deck was shuffled and each player has drawn " << rounds <<  " cards.\n\n";

        for(int i = 0; i < rounds; ++i){
            Card computerCard, humanCard;

            std::cout << "Round " << i+1 << "\n-------\n";
            std::cout << "The computer plays: " << (computerCard = computer.hand.dealCard(0)).printCard() << "\n";
            
            if(computerCard.getColor() == Card::Tiger){
                std::cout << "The computer wins the game!\n\n";
                computer.score += computerCard.getValue();
                *(computerScores.end()-1) += computerCard.getValue();
                *(computerWins.end()-1) += 1;
                break;
            }

            std::cout << "Your hand: " << human.hand.printHand() << "\n";
            std::cout << "Which card do you want to play? ";

            int position;
            auto isPositionValid = [&position, &input, &human]()->bool{
                position = std::stoi(input)-1;
                if(position > human.hand.getHandSize()){
                    std::cout << "Input a number between 1 and " << human.hand.getHandSize() << ": ";
                    return false;
                }
                return true;
            };

            std::getline(cin, input);
            while(!isInputANumber() || !isPositionValid()){
                std::getline(cin, input);
            }

            std::cout << "You played: " << (humanCard = human.hand.dealCard(position)).printCard() << "\n";
            
            if(humanCard.getColor() == Card::Tiger){
                std::cout << "You win the game!\n\n";
                human.score += humanCard.getValue();
                *(humanScores.end()-1) += humanCard.getValue();
                *(humanWins.end()-1) += 1;
                break;
            }
            
            if(computerCard.getValue() > humanCard.getValue()){
                std::cout << "The computer wins this round!\n";
                int score = computerCard.getValue() + humanCard.getValue();
                computer.score += score;
                *(computerScores.end()-1) += score;
                *(computerWins.end()-1) += 1;
            }else if(humanCard.getValue() > computerCard.getValue()){
                std::cout << "You win this round!\n";
                int score = computerCard.getValue() + humanCard.getValue();
                human.score += score;
                *(humanScores.end()-1) += score;
                *(humanWins.end()-1) += 1;
            }else{
                std::cout << "Tie!\n";
            }

            std::cout << "\nCurrent scores:\n";
            std::cout << "Human: " << human.score << "\n";
            std::cout << "Computer: " << computer.score <<"\n\n";
        }

        std::cout << "FINAL SCORE:\n";
        std::cout << "Human: " << human.score << "\n";
        std::cout << "Computer: " << computer.score <<"\n";

        if(human.score == computer.score) std::cout << "Tie Game!\n";
        else std::cout << "\n" << ((human.score > computer.score)? "Human": "Computer") << " has won!\n";

        std::cout << "Type yes to continue playing: ";
        std::getline(cin, input);
        if(input.find("yes") == std::string::npos) break;
        std::cout << "\n";
    };
    
    std::cout << string(32, '-') << "\n";
    std::cout << "\nSummary\n";
    std::cout << "Total Rounds: " << totalRounds << "\n\n";
    
    for(int i = 0; i < totalRounds; i++){
        std::cout << "Round " << i+1 << "\n";
        std::cout << "Computer Score: " << computerScores[i] << "\n";
        std::cout << "Human Score: " << humanScores[i] << "\n";
        std::cout << "Computer Wins: " << computerWins[i] << "\n";
        std::cout << "Human Wins: " << humanWins[i] << "\n\n";
    }
    
    std::cout << "All Rounds\n";
    std::cout << "Computer Total Score: " << std::accumulate(computerScores.begin(), computerScores.end(), 0) << "\n";
    std::cout << "Human Total Score: " << std::accumulate(humanScores.begin(), humanScores.end(), 0) << "\n";
    std::cout << "Computer Total Wins: " << std::accumulate(computerWins.begin(), computerWins.end(), 0) << "\n";
    std::cout << "Human Total Wins: " << std::accumulate(humanWins.begin(), humanWins.end(), 0) << "\n";
    
  return 0;
}
