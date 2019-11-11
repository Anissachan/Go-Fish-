#include <string>
#include "card.h"

using namespace std;

Card::Card() {
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

string Card::toString() const {
    string output = rankString(myRank);
    output += suitString(mySuit);
    return output;
}

bool Card::sameSuitAs(const Card &c) const {
    return c.mySuit == mySuit;
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
    else if(r == 2)
        output = "2";
    else if(r == 3)
        output = "3";
    else if(r == 4)
        output = "4";
    else if(r == 5)
        output = "5";
    else if(r == 6)
        output = "6";
    else if(r == 7)
        output = "7";
    else if(r == 8)
        output = "8";
    else if(r == 9)
        output = "9";
    else if(r == 10)
        output = "10";
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



