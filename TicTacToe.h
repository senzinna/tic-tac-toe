#ifndef TICTACTOE_H
#define TICTACTOE_H
class TicTacToe
{
private:
    enum Status
    {
        WIN,
        DRAW,
        CONTINUE
    }; // enumeration constants
    int board[3][3];

public:
    TicTacToe();              // default constructor
    void makeMove();          // make move
    void printBoard();        // print board
    bool validMove(int, int); // validate move
    bool xoMove(int);         // x o move
    Status gameStatus();      // game status
};                            // end class TicTacToe
#endif
