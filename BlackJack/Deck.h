#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include "Card.h"
#include "Hand.h"

using namespace std;

class Deck {
    private:
        vector<Card> cards;
    public:
        Deck(); // constructor
        void shuffle();
        void reset();
        void deal(Hand&);
};

#endif
