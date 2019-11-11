//
// Created by aniss on 11/9/2019.
//
#include <iostream>
#include <ctime>
#include "deck.h"
#include "card.h"
#include "player.h"

using namespace std;

Deck::Deck() {
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
    //int _rank;
    //string suit;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 52; j++){
            Card(j, i);
        }
    }
}

void Deck::shuffle() {

    for(int i = 0; i < 52; i++) {
        int index1 = (rand() % 13) + 1;
        int index2 = (rand() % 13) + 1;

        Card tempCard = myCards[index1];
        myCards[index1] = myCards[index2];
        myCards[index2] = tempCard;

    }
}

void Deck::dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

Card Deck::dealCard() {
    Card card(0,Card::Suit(0));
    if(size() > 0){
        card = myCards[myIndex];
        myIndex++;
    }
    return card;
}

int Deck::size() const {
    return SIZE - myIndex;
}
