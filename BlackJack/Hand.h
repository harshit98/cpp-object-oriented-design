#define HAND_H

#include <iostream>
#include <vector>
#include "Card.h"

using namespace std;

class Hand {
    private:
        vector<Card> cards;
    public:
        void addCard(Card);
        bool isBust();
        int getCurrentValue();
        void clear();

        friend std::ostream& operator<<(std::ostream&, Hand);
};
