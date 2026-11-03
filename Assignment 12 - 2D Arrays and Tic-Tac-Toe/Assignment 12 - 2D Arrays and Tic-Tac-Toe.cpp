// Nathan
// Ouk
// 0834524@my.msjc.edu
// 11/02/2026
// Assignment 12 - 2D Arrays and Tic-Tac-Toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Create a console tic-tac-toe app that creates a 3 by 3 grid, and allows the user to input either X or O in a space, with whoever gets 3 in a row wins.

#include <iostream>
#include <cstdlib>

using namespace std;

void createGameBoard(char bd[][3]);
void printBoard(char bd[][3]);
bool markSpace(char bd[][3], int row, int col);
bool gameOver(char game[][3], char& whoWon);

int main() {
    char board[3][3];
    bool finished = false;
    int x = 0;
    int y = 0;
    int count = 0;
    char winner = ' ';

    createGameBoard(board);
    printBoard(board);

    while (!finished) {

        if (count % 2 == 0) {
            cout << "Player X's turn.\n";
        }
        else {
            cout << "Player O's turn.\n";
        }

        cout << "Enter row (0-2) and column (0-2) separated by a space: ";

        if (!(cin >> x >> y) || x < 0 || x > 2 || y < 0 || y > 2) {
            cout << "Error: Position must be between 0 and 2. Try again." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (!markSpace(board, x, y)) {
            cout << "That space is already occupied, you need to choose another spot.\n";
            printBoard(board);
            continue;
        }

        count++;

        finished = gameOver(board, winner);

        if (finished && count <= 9) {
            printBoard(board);
            cout << "Player " << winner << " wins!\n";
            break;
        }
        else if (!finished && count == 9) {
            printBoard(board);
            cout << "You managed to tie the computer, congrats!" << endl;
            break;
        }

        printBoard(board);
    }

    return 0;
}

void createGameBoard(char bd[][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            bd[i][j] = '-';
        }
    }
}

void printBoard(char bd[][3]) {
    cout << "Current Board: " << endl;;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << bd[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool markSpace(char bd[][3], int row, int col) {
    static bool xTurn = false;

    xTurn = !xTurn;

    if (bd[row][col] == '-') {
        if (xTurn) {
            bd[row][col] = 'X';
        }
        else {
            bd[row][col] = 'O';
        }

        system("CLS"); 
        return true;
    }

    return false;
}

bool gameOver(char game[][3], char& whoWon) {
    char winner = ' ';

    
    if (game[0][0] != '-' && game[0][0] == game[1][1] && game[0][0] == game[2][2]) {
        winner = game[0][0];
    }
 
    else if (game[2][0] != '-' && game[2][0] == game[1][1] && game[2][0] == game[0][2]) {
        winner = game[2][0];
    }
    else {
     
        for (int row = 0; row < 3; ++row) {
            if (game[row][0] != '-' && game[row][0] == game[row][1] && game[row][0] == game[row][2]) {
                winner = game[row][0];
                break;
            }
            else if (game[0][row] != '-' && game[0][row] == game[1][row] && game[0][row] == game[2][row]) {
                winner = game[0][row];
                break; 
            }
        }
    }

    if (winner == ' ') {
        return false;
    }
    else {
        whoWon = winner;
        return true;
    }
}