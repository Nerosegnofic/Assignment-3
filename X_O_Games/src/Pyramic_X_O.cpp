// Class definition for Pyramic_X_O class
// Author:  Ahmed Abdelnabi
// Date:    12/11/2023
// Version: 1

#include <iostream>
#include <iomanip>
#include "../include/BoardGame_Classes.hpp"

using namespace std;

Pyramic_X_O::Pyramic_X_O() {
    board = new char*;
    board[0] = new char[9];

    for (int j {0}; j < 9; ++j) {
        board[0][j] = ' ';
    }
}

bool Pyramic_X_O::update_board(int x, int y, char mark){
    int position {0};

    if (x == 0 && y == 0) {
        position = 1;
    } else if (x == 1 && y == 0) {
        position = 2;
    } else if (x == 1 && y == 1) {
        position = 3;
    } else if (x == 1 && y == 2) {
        position = 4;
    } else if (x == 2 && y == 0) {
        position = 5;
    } else if (x == 2 && y == 1) {
        position = 6;
    } else if (x == 2 && y == 2) {
        position = 7;
    } else if (x == 2 && y == 3) {
        position = 8;
    } else if (x == 2 && y == 4) {
        position = 9;
    }
    // Only update if move is valid
    if ((position >= 1 && position <= 9) && (board[0][position - 1] == ' ')) {
        board[0][position - 1] = toupper(mark);
        ++n_moves;
        return true;
    }
    return false;
}

void Pyramic_X_O::display_board() {
    cout << setw(25) << "|(0, 0) " << board[0][0] << '|' << endl;
    cout << setw(28) << "----------" << endl;
    cout << "         |(1, 0) " << board[0][1] << "|(1, 1) " << board[0][2] << "|(1, 2) " << board[0][3] << '|' <<  endl;
    cout << "         ----------------------------" << endl;
    cout << "|(2, 0) " << board[0][4] << "|(2, 1) " << board[0][5] << "|(2, 2) " << board[0][6] << "|(2, 3) " << board[0][7] << "|(2, 4) " << board[0][8] << '|' << endl;
    cout << "----------------------------------------------" << endl;
}

bool Pyramic_X_O::is_winner() {
    // Check for diagonals
    if ((board[0][0] == board[0][1] && board[0][1] == board[0][4] && (board[0][0] != ' ' && board[0][1] != ' ' && board[0][4] != ' ')) || (board[0][0] == board[0][3] && board[0][3] == board[0][8]) && (board[0][0] != ' ' && board[0][3] != ' ' && board[0][8] != ' ')) {
        return true;
    // Check for horizontals
    } else if ((board[0][1] == board[0][2] && board[0][2] == board[0][3] && (board[0][1] != ' ' && board[0][2] != ' ' && board[0][3] != ' ')) || ((board[0][4] == board[0][5] && board[0][5] == board[0][6]) && (board[0][4] != ' ' && board[0][5] != ' ' && board[0][6] != ' ')) || (board[0][6] == board[0][7] && board[0][7] == board[0][8]) && (board[0][6] != ' ' && board[0][7] != ' ' && board[0][8] != ' ')  || (board[0][5] == board[0][6] && board[0][6] == board[0][7]) && (board[0][5] != ' ' && board[0][6] != ' ' && board[0][7] != ' ')) {
        return true;
    // Check for verticals
    } else if ((board[0][0] == board[0][2] && board[0][2] == board[0][6]) && (board[0][0] != ' ' && board[0][2] != ' ' && board[0][6] != ' ')) {
        return true;
    }
    return false;
}

bool Pyramic_X_O::is_draw() {
    return n_moves == 9 && !is_winner();
}

bool Pyramic_X_O::game_is_over() {
    return n_moves >= 9;
}