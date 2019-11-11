#include <iostream>
#include "player.h"
#include "card.h"
#include "deck.h"
#include <fstream>

using namespace std;

void dealHand(Deck &d, Player &p, int numCards);

int main(){
    ofstream file("gofish_results.txt");
    int numCards = 7;
    Player p1("Anissa");
    Player p2("Pragna");

    Deck d;
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    if(file.is_open()){
        file<<"Starting game"<<endl;
    }

    file<<p1.getName()<<"'s hand: "<<p1.showHand()<<endl;
    file<<p2.getName()<<"'s hand: "<<p2.showHand()<<endl;
    file<<p1.getName()<<"'s book: "<<p1.showBooks()<<endl;
    file<<p2.getName()<<"'s book: "<<p2.showBooks()<<endl<<endl;


}

void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
