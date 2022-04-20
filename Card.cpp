#include "Card.h"

// constructor to set rank, color, and value
Card::Card(int rank, Color color): rank(rank), color(color){
    switch(color){
        case purple:
            value = rank;
            break;
        case orange:
            value = 2*rank;
            break;
    }
}

// prints color:rank
std::string Card::printCard() const{
    std::string buffer;
    switch(color){
        case purple:
            buffer += "purple";
            break;
        case orange:
            buffer += "orange";
            break;
    }

    return buffer += ":" + std::to_string(rank);
}

// getters
int Card::getRank() const { return rank; }
int Card::getColor() const { return color; }
int Card::getValue() const { return value; }