#include "player.h"
#include "card.h"
#include "deck.h"
#include <iterator>
#include <ctime>

using namespace std;

Player::Player() {
    myName = "";
}

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
    removeCardFromHand(c1);
    removeCardFromHand(c2);
}

Card Player::removeCardFromHand(Card c) {
    Card temp;
    vector<Card>::iterator i ;
    for( i = myHand.begin(); i<myHand.end(); i++){
        temp = *i;
        myHand.erase(i);
        return temp;
    }

}

int Player::getHandSize() const {
    return myHand.size();
}

int Player::getBookSize() const {
    return myBook.size();
}

string Player::showHand() const {
    string hand;
    for(Card card: myHand){
        hand = hand + card.toString() + " ";
    }
    return hand;
}

bool Player::rankInHand(Card c) const {
    bool found = false;
    for(Card card: myHand){
        if(c.getRank() == card.getRank()){
            found = true;
        }
    }
    return found;
}

bool Player::checkHandForPair(Card &c1, Card &c2) {
    vector<Card>::const_iterator i1;
    vector<Card>::const_iterator i2;

    for(i1 = myHand.begin(); i1 < myHand.end(); i1++){
        for(i2 = i1+1; i2 < myHand.end(); i2++){
            if((*i1).getRank() == (*i2).getRank()){
                c1 = *i1;
                c2 = *i2;
                return true;
            }
        }
    }
}

Card Player::chooseCardFromHand() const {
    srand(time(NULL));
    return myHand[(rand() % getHandSize())];
}

bool Player::cardInHand(Card c) const {
    for(Card card: myHand){
        if(card == c)
            return true;
    }

    return false;
}

string Player::showBooks() const {
    vector<Card>::const_iterator i;
    string output;
    for(i=myBook.begin(); i!=myBook.end(); i++){
        output = output + (*i).toString() + " ";
    }
    return output;
}



