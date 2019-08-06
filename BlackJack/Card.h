#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

enum suits { HEARTS, DIAMONDS, SPADES, JOKER, CLUBS };

class Card {
    private:
        int suit;
        int number;
    public:
        Card();    // Default constructor
        Card(int, int);

        // Accessors
        int getSuit();
        int getNumber();

        // Mutators
        void setSuit(int);
        void setNumber(int);

        friend std::ostream& operator<<(std::ostream&, Card&);
};

#endif
