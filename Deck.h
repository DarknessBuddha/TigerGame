#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "Card.h"

class Deck{
    std::vector<Card> deck;

    public:
        Deck();

        void shuffle(); // shuffles the deck
        Card drawCard(); // draws card from deck
        int getDeckSize() const;
};
  

#endif // DECK_H_
