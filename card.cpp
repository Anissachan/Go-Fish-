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
    string output = rankString(myRank);
    output += suitString(mySuit);
    return output;
}

bool Card::sameSuitAs(const Card &c) const {
    if(mySuit == c.mySuit)
        return true;
}

int Card::getRank() const {
    return myRank;
}

string Card::suitString(Card::Suit s) const {
    string output = " ";
    if(s == spades)
        output = "s";
    else if(s == hearts)
        output = "h";
    else if(s == clubs)
        output = "c";
    else output = "d";

    return output;
}

string Card::rankString(int r) const {
    string output = " ";

    if(r == 1)
        output = "A";
    else if(r == 11)
        output = "J";
    else if(r == 12)
        output = "Q";
    else if(r == 13)
        output = "K";

    return output;
}


bool Card::operator==(const Card &rhs) const {
    if(myRank == rhs.myRank && mySuit == rhs.mySuit)
        return true;
}

bool Card::operator!=(const Card &rhs) const {
    if(myRank != rhs.myRank || (myRank == rhs.myRank && mySuit != rhs.mySuit))
        return true;
}

