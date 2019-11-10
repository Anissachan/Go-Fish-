//
// Created by aniss on 11/9/2019.
//
#include "card.h"
#include <string>

using namespace std;

Card::Card(){
    myRank = 1;         //the default card is the ACE of Spades
    mySuit = spades;
}

Card::Card(int rank, Card::Suit s) {
    myRank = rank;
    mySuit = s;
}

string Card::toString() const {
    string _string;
    _string = to_string();
    return(_string);
}

bool Card::sameSuitAs(const Card &c) const {
    if(mySuit == c.mySuit)
        return true;
}

int Card::getRank() const {
    return myRank;
}

string Card::suitString(Suit s) const {
    return (to_string(s));
}

string Card::rankString(int r) const {
    return (to_string(r));
}

bool Card::operator==(const Card &rhs) const {
    if(myRank == rhs.myRank && mySuit == rhs.mySuit)
        return true;
}

bool Card::operator!=(const Card &rhs) const {
    if(myRank != rhs.myRank || (myRank == rhs.myRank && mySuit != rhs.mySuit))
        return true;
}

