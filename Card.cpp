#include "Card.h"

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

std::string Card::printCard() const{
    std::string print;
    switch(color){
        case purple:
            print += "purple";
            break;
        case orange:
            print += "orange";
            break;
    }

    return print += ":" + std::to_string(rank);
}

int Card::getRank() const { return rank; }
int Card::getColor() const { return color; }
int Card::getValue() const { return value; }