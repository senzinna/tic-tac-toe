#include <iostream>
#include <iomanip>
#include "TicTacToe.h"
#include <cstdlib>
//Scott Enzinna
using namespace std;

TicTacToe::TicTacToe()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
    cout << "Tic-Tac-Toe\n";
    printBoard();
    cout << "Directions:\n"
         << "Enter the row and coloumb seperated by a space." << endl;
}

void TicTacToe::printBoard()
{
    system("clear");

    cout << "\n   0    1    2\n\n";
    for (int r = 0; r < 3; ++r)
    {
        cout << r;
        for (int c = 0; c < 3; ++c)
        {
            cout << setw(3) << static_cast<char>(board[r][c]);
            if (c != 2)
                cout << " |";
        } // end for
        if (r != 2)
            cout << "\n ____|____|____\n     |    | \n";
    } // end for
    cout << "\n\n";
}

void TicTacToe::makeMove()
{
    int row, col;

    for (int i = 1; i < 10; i++) // Tell if its player1 or player 2 move
    {
        if (i % 2 != 0)
        {
            cout << "Make a move player1: ";
            cin >> row >> col;
            while (!(validMove(row, col)))
            {
                cout << "\nTry again: ";
                cin >> row >> col;
            }
            board[row][col] = 'X';
            printBoard();
            if (xoMove('X'))
            {
                cout << "\nWinner: Player1!" << endl;
                break;
            }
        }
        else
        {
            cout << "Make a move player2: ";
            cin >> row >> col;
            while (!(validMove(row, col)))
            {
                cout << "\nTry again: ";
                cin >> row >> col;
            }
            board[row][col] = 'O';
            printBoard();
            if (xoMove('O'))
            {
                cout << "\nWinner: Player2!" << endl;
                break;
            }
        }
    }
}

bool TicTacToe::validMove(int a, int b)
{
    if (board[a][b] != ' ' || a > 2 || a < 0 || b > 2 || b < 0)

        return false;

    else

        return true;
}

bool TicTacToe::xoMove(int t)
{
    if (board[0][0] == t && board[0][1] == t && board[0][2] == t)
    {
        return true;
    }
    if (board[1][0] == t && board[1][1] == t && board[1][2] == t)
    {
        return true;
    }
    if (board[2][0] == t && board[2][1] == t && board[2][2] == t)
    {
        return true;
    }
    if (board[0][0] == t && board[1][0] == t && board[2][0] == t)
    {
        return true;
    }
    if (board[0][1] == t && board[1][1] == t && board[2][1] == t)
    {
        return true;
    }
    if (board[0][2] == t && board[1][2] == t && board[2][2] == t)
    {
        return true;
    }
    if (board[0][0] == t && board[1][1] == t && board[2][2] == t)
    {
        return true;
    }
    if (board[0][2] == t && board[1][1] == t && board[2][0] == t)
    {
        return true;
    }
    else
        return false;
}
