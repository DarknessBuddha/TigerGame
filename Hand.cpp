#include "Hand.h"

// constructor that draws N cards from deck
Hand::Hand(Deck& deck, int N){
    for(int i = 0; i < N; ++i){
        hand.push_back(deck.drawCard());
    }
}

// prints the cards in hand
std::string Hand::printHand() const{
    std::stringstream ss;
    for(int i = 0; i < static_cast<int>(hand.size()); ++i){
        ss << "[" << i+1 << "] " << hand[i].printCard() << " "; 
    }
    return ss.str();
}

// removes and returns card from hand
Card Hand::dealCard(int num){
    Card card = hand[num];
    hand.erase(hand.begin() + num);
    return card;
}

// returns amount of cards in hand
int Hand::getHandSize() const{
    return hand.size();
}
