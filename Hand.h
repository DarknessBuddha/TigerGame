#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include <string>
#include <sstream>

#include "Card.h"
#include "Deck.h"

class Hand{
    std::vector<Card> hand;

    public:
        Hand() = default;
        Hand(Deck& deck, int N);

        std::string printHand() const;
        Card dealCard(int num);
        int getHandSize() const;
};

#endif // HAND_H_
