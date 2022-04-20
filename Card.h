#ifndef CARD_H_
#define CARD_H_

#include <string>

class Card{
    public:
        enum Color{purple, orange};
        Card() = default;
        Card(int rank, Color color);

        std::string printCard() const;
        
        // getters
        int getRank() const;
        int getColor() const;
        int getValue() const;
        
    private:
        int rank{0};
        Color color{purple};
        int value{0};
        
};
  

#endif // CARD_H_
