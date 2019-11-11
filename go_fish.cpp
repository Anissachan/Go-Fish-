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

string print(Player p, int turn, Card card){
    string message;
    string Message[5] = {": Do you have a ", " : Go Fish", "draws", ": Yes, I have a ", ": books the "};

    if(turn == ASK)
        message = p.getName() + Message[0] + card.rankString(card.getRank()) + "?" ;

    if(turn == GOFISH)
        message  = p.getName() + Message[1];

    if(turn == DRAW)
        message = p.getName() + Message[2] + card.toString();

    if(turn == YES)
        message = p.getName() + Message[3] + card.rankString(card.getRank());

    if(turn == BOOK)
        message = p.getName() + Message[4] + card.rankString(card.getRank());

    return message;

}

void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
