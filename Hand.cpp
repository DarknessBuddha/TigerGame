#include "Hand.h"

Hand::Hand(Deck& deck, int N){
    for(int i = 0; i < N; ++i){
        hand.push_back(deck.drawCard());
    }
}

std::string Hand::printHand() const{
    std::stringstream ss;
    for(int i = 0; i < static_cast<int>(hand.size()); ++i){
        ss << "[" << i+1 << "] " << hand[i].printCard() << " "; 
    }
    return ss.str();
}

Card Hand::dealCard(int num){
    Card card = hand[num];
    hand.erase(hand.begin() + num);
    return card;
}

int Hand::getHandSize() const{
    return hand.size();
}
