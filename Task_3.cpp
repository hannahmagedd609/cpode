/*
=====================================================================================================================
file  : Task_3.cpp
brief : simple console-based Tic-Tac-Toe game that allows two players to play against each other
author: hana maged mohamed
date  : September 16, 2023
=====================================================================================================================
*/
#include <iostream>
#include <string>
using namespace std;
char Game_Board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; /*creating a 3x3 grid as the game board*/
char Player_1 = ' ';
char Player_2 = ' ';
char winner = ' ';
bool check_for_spaces(char grid[3][3]);
void player1_move(char grid[3][3]);
void player2_move(char grid[3][3]);
void show_current_board(char grid[3][3]);
bool check_for_win(char grid[3][3]);
bool check_for_draw(char grid[3][3]);
void reset_board(char grid[3][3]);

int main()
{
    int turn = 1;        /*creating a variable to hold the turn that needs to be switched on*/
    char Player_X = 'X'; /*a variable to store the 'X' character*/
    char Player_O = 'O'; /*a variable to store the 'O' character*/
    bool draw = false, win = false;
    string play_again = "YES";
    cout << "Welcome to Tic Tac Toe: The Ultimate Showdown! \n";
    cout << "Get ready to unleash your strategic genius!\n";
    cout << "Let's goo!\n";
    /*prompting players to choose X or O*/
    cout << "Player one, choose X or O: ";
    cin >> Player_1;
    if (Player_1 == Player_X)
    {
        Player_1 = Player_X; /*assigning X to player 1*/
        Player_2 = Player_O; /*assigning O to player 2*/
    }
    else
    {
        Player_1 = Player_O; /*assigning O to player 1*/
        Player_2 = Player_X; /*assigning X to player 2*/
    }
    cout << "Player two takes " << Player_2 << " then.\n";
    /*game board grid*/
    cout << "Before you begin here's a hint for the game board positions: \n";
    cout << "     |     |     \n";
    cout << "  "
         << "00"
         << " |  "
         << "01"
         << " |  "
         << "02"
         << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  "
         << "10"
         << " |  "
         << "11"
         << " |  "
         << "12"
         << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  "
         << "20"
         << " |  "
         << "21"
         << " |  "
         << "22"
         << "  \n";
    cout << "     |     |     \n";
    cout << "\n";
    /*game logic goes here*/
    while (play_again == "YES")
    {
        while ((win != true) && (check_for_spaces(Game_Board)))
        {
            /*alternate turns between 'X and 'O'players*/
            switch (turn)
            {
            case 1:
                player1_move(Game_Board);
                turn = 2;
                break;
            case 2:
                player2_move(Game_Board);
                turn = 1;
                break;
            }
            show_current_board(Game_Board);
            win = check_for_win(Game_Board);
            draw = check_for_draw(Game_Board);
            if (win)
            {
                cout << "Congratulations! Player with " << winner << " has won.\n";
                cout << "The result is: \n";
                show_current_board(Game_Board);
            }
            else if (draw)
            {
                cout << "It's a tie!! \n";
                break;
            }
            else
            {
                cout << "The game is ongoing, continue playing. \n";
            }
        }
        cout << "Do you want to have a rematch? (yes or no) ";
        cin.ignore();
        cin >> play_again;
        if (play_again == "YES")
        {
            reset_board(Game_Board);
            win = false;
            draw = false;
        }
        else
        {
            cout << "Thanks for joining in! \n";
            break;
        }
    }

    return 0;
}
bool check_for_spaces(char grid[3][3])
{
    /*checks if there's any free space*/
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (grid[i][j] == ' ')
                return true;
        }
    }
    return false;
}
void player1_move(char grid[3][3])
{
    int row, column;
    do
    {
        /*prompt player 1 to enter his move only if it's a valid move*/
        cout << "Player 1, please enter your move and specify row and column positions: ";
        cin >> Player_1 >> row >> column;
        if (grid[row][column] == ' ')
        {
            grid[row][column] = Player_1;
        }
        else
        {
            cout << "ALREADY OCCUPIED! try again. \n";
        }

    } while (grid[row][column] == ' ');
}
void player2_move(char grid[3][3])
{
    int row, column;
    do
    {
        /*prompt player 2 to enter his move only if it's a valid move*/
        cout << "Player 2, please enter your move and specify row and column positions: ";
        cin >> Player_2 >> row >> column;
        if (grid[row][column] == ' ')
        {
            grid[row][column] = Player_2;
        }
        else
        {
            cout << "ALREADY OCCUPIED! try again. \n";
        }
    } while (grid[row][column] == ' ');
}
void show_current_board(char grid[3][3])
{
    /*showing the game board*/
    cout << "     |     |     \n";
    cout << "  " << grid[0][0] << "  |  " << grid[0][1] << "  |  " << grid[0][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << grid[1][0] << "  |  " << grid[1][1] << "  |  " << grid[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << grid[2][0] << "  |  " << grid[2][1] << "  |  " << grid[2][2] << "  \n";
    cout << "     |     |     \n";
    cout << "\n";
}
bool check_for_win(char grid[3][3])
{
    /*checking horizontal win*/
    for (int i = 0; i < 3; ++i)
    {
        if ((grid[i][0] != ' ') && (grid[i][0] == grid[i][1]) && (grid[i][1] == grid[i][2]))
        {
            winner = grid[i][0];
            return true;
        }
    }
    /*checking vertical win*/
    for (int i = 0; i < 3; ++i)
    {
        if ((grid[0][i] != ' ') && (grid[0][i] == grid[1][i]) && (grid[1][i] == grid[2][i]))
        {
            winner = grid[0][i];
            return true;
        }
    }
    /*checking main diagonal win*/
    if ((grid[0][0] != ' ') && (grid[0][0] == grid[1][1]) && (grid[1][1] == grid[2][2]))
    {
        winner = grid[0][0];
        return true;
    }
    /*checking counter diagonal win*/
    if ((grid[0][2] != ' ') && (grid[0][2] == grid[1][1]) && (grid[1][1] == grid[2][0]))
    {
        winner = grid[0][2];
        return true;
    }
    return false;
}

bool check_for_draw(char grid[3][3])
{
    /*checking for a draw*/
    int spaces = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (grid[i][j] == ' ')
                ++spaces;
        }
    }
    if (spaces == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void reset_board(char grid[3][3])
{
    /*clearing the game board for another round*/
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            grid[i][j] = ' ';
        }
    }
}
