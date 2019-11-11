#include <iostream>
#include "player.h"
#include "card.h"
#include "deck.h"
#include <fstream>

using namespace std;

void dealHand(Deck &d, Player &p, int numCards);
string print(Player p, int turn, Card card);
Player* playerTurn(int player_turn, Player *p1, Player *p2);

int current_turn = 1;

const int ASK = 0;
const int GOFISH = 1;
const int DRAW = 2;
const int YES = 3;
const int BOOK = 4;

int main(){
    ofstream file("gofish_results.txt");
    int numCards = 7;
    Player p1("Anissa");
    Player p2("Pragna");

    Deck d;
    d.shuffle();
    Card c1, c2, currentCard;

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    if(file.is_open()){
        file<<"Starting game"<<endl;
    }

    file<<p1.getName()<<"'s hand: "<<p1.showHand()<<endl;
    file<<p2.getName()<<"'s hand: "<<p2.showHand()<<endl;
    file<<p1.getName()<<"'s book: "<<p1.showBooks()<<endl;
    file<<p2.getName()<<"'s book: "<<p2.showBooks()<<endl<<endl;

    while(p1.checkHandForPair(c1, c2)){
        p1.bookCards(c1, c2);
        file<<p1.getName()<<" has a pair "<<p1.showBooks()<<endl;
    }

    while(p2.checkHandForPair(c1, c2)){
        p2.bookCards(c1, c2);
        file<<p2.getName()<<" has a pair "<<p2.showBooks()<<endl<<endl;
    }

    while(d.size() != 0){
        string message;

        Player* currentPlayer = playerTurn(current_turn, &p1, &p2);
        Player* otherPlayer = playerTurn(1-current_turn, &p1, &p2);

        file<<p1.getName()<<"'s hand: "<<p1.showHand()<<endl;
        file<<p2.getName()<<"'s hand: "<<p2.showHand()<<endl;
        file<<p1.getName()<<"'s book: "<<p1.showBooks()<<endl;
        file<<p2.getName()<<"'s book: "<<p2.showBooks()<<endl<<endl;

        currentCard = currentPlayer->chooseCardFromHand();
        message = print(*currentPlayer, ASK, currentCard);
        file<<message<<endl;

        if(otherPlayer->sameRankInHand(currentCard)){
            message = print(*otherPlayer, YES, currentCard);
            file<<message<<endl<<endl;
            otherPlayer->removeCardFromHand(currentCard);
            currentPlayer->addCard(currentCard);
            if(currentPlayer->checkHandForPair(c1, c2)){
                currentPlayer->bookCards(c1, c2);
                message = print(*currentPlayer, BOOK, currentCard);
                file<<message<<endl;
            }


        }
        else {
            message = print(*otherPlayer, GOFISH, currentCard);
            file<<message<<endl<<endl;
            Card newCard = d.dealCard();
            currentPlayer->addCard(newCard);
            message = print(*currentPlayer, DRAW, newCard);
            file<<message<<endl;
            if(currentPlayer->checkHandForPair(c1, c2)){
                currentPlayer->bookCards(c1, c2);
                message = print(*currentPlayer, BOOK, currentCard);
                file<<message<<endl;
            }

        }


        break;



    }
}

string print(Player p, int turn, Card card){
    string message;
    Card::Suit s;
    string Message[5] = {": Do you have a ", " : Go Fish", " draws ", ": Yes, I have a ", " books the "};

    if(turn == ASK)
        message = p.getName() + Message[0] + card.rankString(card.getRank()) + card.suitString(s) + "?" ;

    if(turn == GOFISH)
        message  = p.getName() + Message[1];

    if(turn == DRAW)
        message = p.getName() + Message[2] + card.toString();

    if(turn == YES)
        message = p.getName() + Message[3] + card.rankString(card.getRank());

    if(turn == BOOK)
        message = p.getName() + Message[4] + card.rankString(card.getRank()) + card.suitString(s) ;

    return message;

}

Player* playerTurn(int player_turn, Player *p1, Player *p2){
    if(player_turn == 1) {
        return p2;
    }else {
        return p1;
    }
}


void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
