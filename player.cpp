#include "player.h"
#include "card.h"
#include "deck.h"
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

Player::Player() {
    myName = "";
}

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(removeCardFromHand(c1));
    myBook.push_back(removeCardFromHand(c2));

}

Card Player::removeCardFromHand(Card c) {
    Card temp;
    vector<Card>::iterator i;
    i = find(myHand.begin(), myHand.end(), c);
    temp = *i;
    myHand.erase(i);
    return temp;
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

bool Player::sameRankInHand(Card c) const {
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

    for(int i =0; i < myHand.size() - 1; i++){
        for(int j = 1; j < myHand.size(); j++){
            if(myHand.at(i).getRank() == myHand.at(j).getRank()){
                c1 = myHand.at(i);
                c2 = myHand.at(j);
                return true;
            }
        }
    }
    return false;
}

Card Player::chooseCardFromHand() const {
    srand(time(NULL));
    return myHand.at((rand() % getHandSize()));
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




