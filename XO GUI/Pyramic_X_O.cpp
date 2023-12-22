// // Class definition for Pyramic_X_O class
// // Author:  Ahmed Abdelnabi
// // Date:    12/11/2023
// // Version: 1

// #include "BoardGame_Classes.h"


// Pyramic_X_O::Pyramic_X_O() {
//     board = new char*;
//     board[0] = new char[9];

//     for (int j {0}; j < 9; ++j) {
//         board[0][j] = ' ';
//     }
// }

// bool Pyramic_X_O::update_board(int x, int y, char mark){
//     int position;

//     if (x == 0 && y == 0) {
//         position = 1;
//     } else if (x == 1 && y == 0) {
//         position = 2;
//     } else if (x == 1 && y == 1) {
//         position = 3;
//     } else if (x == 1 && y == 2) {
//         position = 4;
//     } else if (x == 2 && y == 0) {
//         position = 5;
//     } else if (x == 2 && y == 1) {
//         position = 6;
//     } else if (x == 2 && y == 2) {
//         position = 7;
//     } else if (x == 2 && y == 3) {
//         position = 8;
//     } else if (x == 2 && y == 4) {
//         position = 9;
//     } else {
//         return false;
//     }
//     // Only update if move is valid
//     if (board[0][position - 1] == ' ') {
//         board[0][position - 1] = toupper(mark);
//         ++n_moves;
//         return true;
//     }
//     return false;
// }

// void Pyramic_X_O::display_board() {
//     cout << "                  I(0, 0) " << board[0][0] << 'I' << endl;
//     cout << "                  ----------" << endl;
//     cout << "         I(1, 0) " << board[0][1] << "I(1, 1) " << board[0][2] << "I(1, 2) " << board[0][3] << 'I' <<  endl;
//     cout << "         ----------------------------" << endl;
//     cout << "I(2, 0) " << board[0][4] << "I(2, 1) " << board[0][5] << "I(2, 2) " << board[0][6] << "I(2, 3) " << board[0][7] << "I(2, 4) " << board[0][8] << 'I' << endl;
//     cout << "----------------------------------------------" << endl;
// }

// bool Pyramic_X_O::is_winner() {
//     // Check for diagonals
//     if ((board[0][0] == board[0][1] && board[0][1] == board[0][4] && (board[0][0] != ' ' && board[0][1] != ' ' && board[0][4] != ' ')) || (board[0][0] == board[0][3] && board[0][3] == board[0][8]) && (board[0][0] != ' ' && board[0][3] != ' ' && board[0][8] != ' ')) {
//         return true;
//         // Check for horizontals
//     } else if ((board[0][1] == board[0][2] && board[0][2] == board[0][3] && (board[0][1] != ' ' && board[0][2] != ' ' && board[0][3] != ' ')) || ((board[0][4] == board[0][5] && board[0][5] == board[0][6]) && (board[0][4] != ' ' && board[0][5] != ' ' && board[0][6] != ' ')) || (board[0][6] == board[0][7] && board[0][7] == board[0][8]) && (board[0][6] != ' ' && board[0][7] != ' ' && board[0][8] != ' ')  || (board[0][5] == board[0][6] && board[0][6] == board[0][7]) && (board[0][5] != ' ' && board[0][6] != ' ' && board[0][7] != ' ')) {
//         return true;
//         // Check for verticals
//     } else if ((board[0][0] == board[0][2] && board[0][2] == board[0][6]) && (board[0][0] != ' ' && board[0][2] != ' ' && board[0][6] != ' ')) {
//         return true;
//     }
//     return false;
// }

// bool Pyramic_X_O::is_draw() {
//     return n_moves == 9 && !is_winner();
// }

// bool Pyramic_X_O::game_is_over() {
//     return n_moves >= 9;
// }
