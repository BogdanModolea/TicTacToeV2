#include <bits/stdc++.h>

void show_board(char board[][3])
{
    system("cls");
    std::cout << "Tic Tac Toe Alpha V2:D\n";
    std::cout << "Use numpad";
    for(int i = 3; i >= 0; i--)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cout << board[i][j] << ' ';
        }
        std::cout << '\n';
    }
}


bool open_position(char board[][3], int x,int y)
{
    return (!board[x][y]);
}

bool win(char board[][3], char piece)
{
    //Check First Line
    if(board[0][0] == piece && board[0][0] == board[0][1] && board[0][1] == board[0][2]) return true;

    //Check Second Line
    if(board[1][0] == piece && board[1][0] == board[1][1] && board[1][1] == board[1][2]) return true;

    //Check Third Line
    if(board[2][0] == piece && board[2][0] == board[2][1] && board[2][1] == board[2][2]) return true;

    //Check First Column
    if(board[0][0] == piece && board[0][0] == board[1][0] && board[1][0] == board[2][0]) return true;

    //Check Second Column
    if(board[0][1] == piece && board[0][1] == board[1][1] && board[1][1] == board[2][1]) return true;

    //Check Third Column
    if(board[0][2] == piece && board[0][2] == board[1][2] && board[1][2] == board[2][2]) return true;

    //Check Positively Sloped Diagonals
    if(board[0][0] == piece && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;

    //Check Negatively Sloped Diagonals
    if(board[0][2] == piece && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

bool is_full(char board[][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(!board[i][j]) return false;
        }
    }
    return true;
}

void multiplayer(char player1, char player2, int winner[],int turn, bool game_over,char board[][3],int piece,int &close)
{
    std::cout << "Player 1 please choise your character (X/O): "; std::cin >> player1;
    if(player1 == 'X') player2 = 'O';
    else player2 = 'X';
    winner[player1]=1;
    winner[player2]=2;
        srand(time(0));
    turn = rand()%2;
    while(!game_over)
    {
        show_board(board);
        if(turn == 0)
        {
            std::cout << "Player 1 please make your choise: "; std::cin>>piece;
            switch(piece){
                case 1:
                    if(open_position(board,0,0)){
                        board[0][0] = player1;
                    }
                    else turn--;
                    break;
                case 2:
                    if(open_position(board,0,1)){
                        board[0][1] = player1;
                    }
                    else turn--;
                    break;
                case 3:
                    if(open_position(board,0,2)){
                        board[0][2] = player1;
                    }
                    else turn--;
                    break;
                case 4:
                    if(open_position(board,1,0)){
                        board[1][0] = player1;
                    }
                    else turn--;
                    break;
                case 5:
                    if(open_position(board,1,1)){
                        board[1][1] = player1;
                    }
                    else turn--;
                    break;
                case 6:
                    if(open_position(board,1,2)){
                        board[1][2] = player1;
                    }
                    else turn--;
                    break;
                case 7:
                    if(open_position(board,2,0)){
                        board[2][0] = player1;
                    }
                    else turn--;
                    break;
                case 8:
                    if(open_position(board,2,1)){
                        board[2][1] = player1;
                    }
                    else turn--;
                    break;
                case 9:
                    if(open_position(board,2,2)){
                        board[2][2] = player1;
                    }
                    else turn--;
                    break;
            }
        }
        else{
            std::cout << "Player 2 please make your choise: "; std::cin>>piece;
            switch(piece){
                case 1:
                    if(open_position(board,0,0)){
                        board[0][0] = player2;
                    }
                    else turn--;
                    break;
                case 2:
                    if(open_position(board,0,1)){
                        board[0][1] = player2;
                    }
                    else turn--;
                    break;
                case 3:
                    if(open_position(board,0,2)){
                        board[0][2] = player2;
                    }
                    else turn--;
                    break;
                case 4:
                    if(open_position(board,1,0)){
                        board[1][0] = player2;
                    }
                    else turn--;
                    break;
                case 5:
                    if(open_position(board,1,1)){
                        board[1][1] = player2;
                    }
                    else turn--;
                    break;
                case 6:
                    if(open_position(board,1,2)){
                        board[1][2] = player2;
                    }
                    else turn--;
                    break;
                case 7:
                    if(open_position(board,2,0)){
                        board[2][0] = player2;
                    }
                    else turn--;
                    break;
                case 8:
                    if(open_position(board,2,1)){
                        board[2][1] = player2;
                    }
                    else turn--;
                    break;
                case 9:
                    if(open_position(board,2,2)){
                        board[2][2] = player2;
                    }
                    else turn--;
                    break;
            }
        }
        if(win(board,'X')){
            show_board(board);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),224);
            std::cout << "PLAYER "<< winner['X'] << " WINS!!!\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            std::cout << "Press 0 to close\n\n";
            std::cin >> close;
            game_over = true;
        }

        else if(win(board,'O')){
            show_board(board);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),224);
            std::cout << "PLAYER "<< winner['O'] << " WINS!!!\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            std::cout << "Press 0 to close\n\n";
            std::cin >> close;
            game_over = true;
        }

        else {
            if(is_full(board)){
                show_board(board);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),224);
                std::cout << "It's a tie!\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                std::cout << "Press 0 to close\n\n";
                std::cin >> close;
                game_over = true;
            }
        }

        turn++;
        turn %= 2;
    }
}

void singleplayer(char player1, char player2, int winner[],int turn, bool game_over,char board[][3],int piece,int &close){
    std::cout << "Player 1 please choise your character (X/O): "; std::cin >> player1;
    if(player1 == 'X') player2 = 'O';
    else player2 = 'X';
    winner[player1]=1;
    winner[player2]=2;
    srand(time(0));
    turn = rand()%2;
    while(!game_over)
    {
        show_board(board);
        if(turn == 0)
        {
            std::cout << "Player 1 please make your choise: "; std::cin>>piece;
            switch(piece){
                case 1:
                    if(open_position(board,0,0)){
                        board[0][0] = player1;
                    }
                    else turn--;
                    break;
                case 2:
                    if(open_position(board,0,1)){
                        board[0][1] = player1;
                    }
                    else turn--;
                    break;
                case 3:
                    if(open_position(board,0,2)){
                        board[0][2] = player1;
                    }
                    else turn--;
                    break;
                case 4:
                    if(open_position(board,1,0)){
                        board[1][0] = player1;
                    }
                    else turn--;
                    break;
                case 5:
                    if(open_position(board,1,1)){
                        board[1][1] = player1;
                    }
                    else turn--;
                    break;
                case 6:
                    if(open_position(board,1,2)){
                        board[1][2] = player1;
                    }
                    else turn--;
                    break;
                case 7:
                    if(open_position(board,2,0)){
                        board[2][0] = player1;
                    }
                    else turn--;
                    break;
                case 8:
                    if(open_position(board,2,1)){
                        board[2][1] = player1;
                    }
                    else turn--;
                    break;
                case 9:
                    if(open_position(board,2,2)){
                        board[2][2] = player1;
                    }
                    else turn--;
                    break;
            }
        }
        else{
            piece = rand()%9; piece++;
            switch(piece){
                case 1:
                    if(open_position(board,0,0)){
                        board[0][0] = player2;
                    }
                    else turn--;
                    break;
                case 2:
                    if(open_position(board,0,1)){
                        board[0][1] = player2;
                    }
                    else turn--;
                    break;
                case 3:
                    if(open_position(board,0,2)){
                        board[0][2] = player2;
                    }
                    else turn--;
                    break;
                case 4:
                    if(open_position(board,1,0)){
                        board[1][0] = player2;
                    }
                    else turn--;
                    break;
                case 5:
                    if(open_position(board,1,1)){
                        board[1][1] = player2;
                    }
                    else turn--;
                    break;
                case 6:
                    if(open_position(board,1,2)){
                        board[1][2] = player2;
                    }
                    else turn--;
                    break;
                case 7:
                    if(open_position(board,2,0)){
                        board[2][0] = player2;
                    }
                    else turn--;
                    break;
                case 8:
                    if(open_position(board,2,1)){
                        board[2][1] = player2;
                    }
                    else turn--;
                    break;
                case 9:
                    if(open_position(board,2,2)){
                        board[2][2] = player2;
                    }
                    else turn--;
                    break;
            }
        }
        if(win(board,'X')){
            show_board(board);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),224);
            std::cout << "PLAYER "<< winner['X'] << " WINS!!!\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            std::cout << "Press 0 to close\n\n";
            std::cin >> close;
            game_over = true;
        }

        else if(win(board,'O')){
            show_board(board);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),224);
            std::cout << "PLAYER "<< winner['O'] << " WINS!!!\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            std::cout << "Press 0 to close\n\n";
            std::cin >> close;
            game_over = true;
        }

        else {
            if(is_full(board)){
                show_board(board);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),224);
                std::cout << "It's a tie!\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                std::cout << "Press 0 to close\n\n";
                std::cin >> close;
                game_over = true;
            }
        }

        turn++;
        turn %= 2;
    }
}
