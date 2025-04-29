#ifndef DECK_H_
#define DECK_H_

#include <algorithm>
#include <random>
#include <string>
#include <vector>

typedef unsigned int deck_count;

struct Card {
  std::string suit;
  std::string value;

  Card(std::string suit, std::string value) {
    this->suit = suit;
    this->value = value;
  }
};

struct Deck {
private:
  std::vector<Card> *cards;

public:
  Deck() {
    this->cards = new std::vector<Card>();
    this->cards->push_back(Card("Hearts", "King"));
    this->cards->push_back(Card("Spades", "King"));
    this->cards->push_back(Card("Clubs", "King"));
    this->cards->push_back(Card("Diamonds", "King"));
  }

  void shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(this->cards->begin(), this->cards->end(), g);
  }

  std::vector<Card>* take(const deck_count n) {
    std::vector<Card>* ret = new std::vector<Card>;
    for (std::vector<Card>::iterator it = this->cards->begin();
         it != (this->cards->begin() + n); it++) {
      ret->push_back(*it);
      this->cards->erase(it);
    }
    return ret;
  }

  ~Deck() { delete this->cards; }
};

struct Dealer {
private:
  std::vector<Deck *> *decks;

  Deck * get_random()
  {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(this->decks->begin(), this->decks->end(), g);
    return this->decks->at(0);
  }

public:
  Dealer() {
    Deck *d = new Deck();
    this->decks = new std::vector<Deck *>();
    this->decks->push_back(d);
  }

  ~Dealer() {
    for (Deck *d : (*this->decks)) {
      delete d;
    }
    // for an array is
    // delete [] array;
    delete this->decks;
  }

  Dealer(deck_count deckCount) {
    this->decks = new std::vector<Deck *>();
    for (deck_count i = 0; i < deckCount; i++) {
      Deck *d = new Deck();
      this->decks->push_back(d);
    }
  }

  std::vector<Card>* deal(const deck_count n) {
    Deck *d = this->decks->at(0);
    return d->take(n);
  }
};

#endif // DECK_H_
