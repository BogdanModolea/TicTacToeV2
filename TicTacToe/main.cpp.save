#include <bits/stdc++.h>
#include <windows.h>
#include "rules.h"
using namespace std;

int player, no_players;

char board[3][3];

int turn, piece;

char player1, player2;

bool game_over = false;

int winner[89];

int close = 1;

int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    cout << "Welcom to the Tic Tac Toe V2 :D! I hope you will enjoy it! \nPlease select the number of players: "; cin >> no_players;
    while(no_players < 1 || no_players > 2){
            system("cls");
            cout << "Please enter a valid number of players!\n";
            cout << "Enter the number of players: "; cin >> no_players;
    }
    if(no_players == 2){
        system("cls");
        multiplayer(player1,player2,winner,turn,game_over,board,piece,close);
        if(!close) return 0;
    }
    else if(no_players == 1){
        system("cls");
        singleplayer(player1,player2,winner,turn,game_over,board,piece,close);
        if(!close) return 0;
    }
}
