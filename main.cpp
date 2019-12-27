// T3, Tic Tac Toe ASAP(As Small As Possible)
// What is tic tac toe
#include <iostream>

using namespace std;

const int BOARD_WIDTH = 3, BOARD_HEIGHT = 3;

char board[BOARD_WIDTH][BOARD_HEIGHT] = {
        { '?', '?' , '?' },
        { '?', '?' , '?' },
        { '?', '?' , '?' } };

void displayBoard()
{
    for (int row = 0; row < BOARD_WIDTH; row++)
    {
        for (int col = 0; col < BOARD_HEIGHT; col++)
        {
            if (col != BOARD_HEIGHT - 1)
            {
                cout << board[row][col] << " | ";
            }
            else
            {
                cout << board[row][col] << endl;
            }
        }
        if (row != BOARD_WIDTH - 1)
            cout << "---------" << endl;
    }
}

void makeMove(char sign)
{
    bool turn_over = false;
    int x = 0, y = 0;
    while (!turn_over)
    {
        cin >> x >> y;
        if (x >= 0 && x < BOARD_WIDTH && y >= 0 && y < BOARD_HEIGHT)
        {
            board[x][y] = sign;
            displayBoard();
            turn_over = true;
        }
        else
        {
            cout << "Bad move, try again." << endl;
        }
    }
    cout << endl;
}

bool isGameOver(char sign)
{
    int row = 0, col = 0;

    //(1 == 2) && (2 == 3) daisy chaining

    // row/horizontal test
    for (row = 0; row < BOARD_WIDTH; row++)
    {
        col = 0;

        if ((sign == board[row][col]) &&
                (board[row][col] == board[row][++col]) &&
                (board[row][col] == board[row][++col]))
        {
            return true;
        }
    }

    // col/vertical test
    for (col = 0; col < BOARD_HEIGHT; col++)
    {
        row = 0;
        if (sign == board[row][col] &&
            board[row][col]  == board[++row][col] &&
            board[row][col] == board[++row][col])
        {
            return true;
        }
    }

    // +row, +col/ downhill diagonal test
    row = 0, col = 0;
    if (sign == board[row][col] &&
        board[row][col] == board[++row][++col] &&
        board[row][col] == board[++row][++col])
    {
        return true;
    }

    // -row, +col/ hill diagonal test
    row = 2, col = 0;
    return sign == board[row][col] &&
           board[row][col] == board[--row][++col] &&
           board[row][col] == board[--row][++col];
}

int main()
{
    cout << "T3" << endl;
/*
    // Test horizontal

    board[0][2] = 'X';
    displayBoard();

    bool test = board[0][0] == board[0][1]  && board[0][1] == board[0][2];

    game_over = isGameOver('X');
    cout << game_over;
*/
    board[0][0] = 'X';
    board[0][1] = 'X';
    bool game_over = false;
    displayBoard();
    while (!game_over)
    {
        cout << "Player 1 make move" << endl;
        makeMove('X');
        game_over = isGameOver('X');

        cout << "Player 2 make move" << endl;
        makeMove('O');

        if (!game_over)
            game_over = isGameOver('O');
    }
    cout << "GAME OVER!" << endl;

}

/**
todo
Down The Road:
move cursor over square to make move
show 1 2 3 over the top and 1 2 3 down the side
make entire game completely independent of max rows and columns
more sophisticated isGameOver function
no magic numbers
make board apart of a class
test cases
*/



