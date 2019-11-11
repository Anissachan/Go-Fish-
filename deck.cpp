#include "player.h"
#include "deck.h"
#include "card.h"
#include <ctime>

using namespace std;

Deck::Deck() {
    myIndex = 0;

    int suit;
    int rank;
    int index = 0;

    for(suit = 0; suit<4; suit++){
        for(rank = 1; rank<14; rank++){
            myCards[index] = Card(rank, Card::Suit(suit));
            index++;
        }
    }
}

void Deck::shuffle() {
    srand(time(NULL));

    for(int i=0; i<size(); i++){
        int i1 = rand()%size();
        int i2 = rand()%size();

        Card temp = myCards[i1];
        myCards[i1] = myCards[i2];
        myCards[i2] = temp;
    }
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
