#include "Deck.h"
#include <ctime>
#include <algorithm>
#include <random>

// Populate Deck with 52 cards, unshuffled.
Deck::Deck() {
    for (int i=HEARTS; i <= CLUBS; i++) {
        for (int j=1; j < 13; j++) {
            this->cards.push_back(Card(i,j));
        }
    }

    srand(time(NULL));
}

// Deals a single card and removes from Deck
void Deck::deal(Hand &h) {
    h.addCard(this->cards.back());
    this->cards.pop_back();
}

void Deck::shuffle() {
    auto _shuffle = std::default_random_engine {};
    std::shuffle(std::begin(cards), std::end(cards), _shuffle);
}
