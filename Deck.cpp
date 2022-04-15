#include "Deck.h"

Deck::Deck(){
    for(int i = 1; i <= 10; i++){
        deck.push_back(Card(i, Card::purple));
        deck.push_back(Card(i, Card::orange));
    }
    deck.push_back(Card(10, Card::Tiger));
}


void Deck::shuffle(){
    std::srand(std::time(0));
    std::random_shuffle(deck.begin(), deck.end());
}

Card Deck::drawCard(){
    Card card = deck.back();
    deck.pop_back();
    return card;
}

int Deck::getDeckSize() const{
    return deck.size();
}
