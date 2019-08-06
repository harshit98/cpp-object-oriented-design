#include "Hand.h"

void Hand::addCard(Card c) {
    this->cards.push_back(c);
}

int Hand::getCurrentValue() {
    int value = 0;
    int aceCount = 0;

    for (Card c : this->cards) {
        if (c.getNumber() != 1) {
            // card is not ace
            if (c.getNumber() > 9) {
                // Jack, Queen or King
                value += 10;
            } else {
                value += c.getNumber();
            }
        } else {
            aceCount++;
        }
    }

    // more than one ace
    while (aceCount > 1) {
        value++;
        aceCount--;
    }

    // if there is single ace
    if (aceCount) {
        if ((value + 11) <= 21) {
            value += 11;
        } else {
            value++;
        }
    }

    return value;
}

// if value > 21 then you've been busted
bool Hand::isBust() {
    if (this->getCurrentValue() > 21) {
        return true;
    } else {
        return false;
    }
}

// reset hand
void Hand::clear() {
    this->cards.clear();
}

std::ostream& operator << (std::ostream& strm, Hand h) {
    strm << "Cards in hand: \n";

    if (h.cards.size() > 0) {
        for (Card c : h.cards) {
            strm << "\t" << c << std::endl;
        }
    } else {
        strm << "\t" << "Your hand is empty.\n";
    }

    return strm;
}
