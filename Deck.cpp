#include "Deck.h"

// builds and pushes 10 purple and orange cards
Deck::Deck(){
    for(int i = 1; i <= 10; i++){
        deck.push_back(Card(i, Card::purple));
        deck.push_back(Card(i, Card::orange));
    }
}

// shuffles the deck
void Deck::shuffle(){
    std::srand(std::time(0));
    std::random_shuffle(deck.begin(), deck.end());
}

// removes and returns card from the top
Card Deck::drawCard(){
    Card card = deck.back();
    deck.pop_back();
    return card;
}

// returns size of deck
int Deck::getDeckSize() const{
    return deck.size();
}
