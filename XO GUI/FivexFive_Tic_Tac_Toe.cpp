// #include"BoardGame_Classes.h"

// FivexFive_Tic_Tac_Toe::FivexFive_Tic_Tac_Toe() {
//     n_rows = n_cols = 5;
//     n_moves = 0;
//     board = new char*[n_rows];
//     for (int i = 0; i < n_rows; i++) {
//         board [i] = new char[n_cols];
//         for (int j = 0; j < n_cols; j++)
//             board[i][j] = 0;
//     }
// }

// bool FivexFive_Tic_Tac_Toe::update_board(int x, int y, char symbol) {
//     if(x < 0 || x > 5 || y < 0 || y > 5 || board[x][y] != 0)
//         return false;
//     else{
//         board[x][y] = toupper(symbol);
//         n_moves++;
//         return true;
//     }
// }

// void FivexFive_Tic_Tac_Toe::display_board() {
//     for (int i=0; i < 5; ++i) {
//         cout << "\n| ";
//         for (int j = 0; j<5; ++j) {
//             cout << "(" << i << "," << j << ")";
//             cout << setw(4) << board [i][j] << " |";
//         }
//         cout << "\n---------------------------------------------------------";
//     }
//     cout << endl;
// }

// int FivexFive_Tic_Tac_Toe::count_threes(char symbol) {
//     int countX = 0, countO = 0;
//     //horizontal counting
//     for (int i = 0; i < 5; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             bool flag = false;
//             int l = j, r = j+2;
//             if(board[i][l] != board[i][r])
//                 continue;
//             l++;
//             while (l != r){
//                 if(board[i][l] != board[i][r])
//                     break;
//                 l++;
//                 flag = true;
//             }
//             if(flag) {
//                 if (board[i][r] == 'X')
//                     countX++;
//                 if (board[i][r] == 'O')
//                     countO++;
//             }
//         }
//     }
//     //vertical counting
//     for (int col = 0; col < 5; ++col) {
//         for (int row = 0; row < 3; ++row) {
//             bool flag = false;
//             int l=row, r=row+2;
//             if(board[l][col] != board[r][col])
//                 continue;
//             l++;
//             while (l != r){
//                 if(board[l][col] != board[r][col])
//                     break;
//                 l++;
//                 flag = true;
//             }
//             if(flag) {
//                 if (board[r][col] == 'X')
//                     countX++;
//                 if (board[r][col] == 'O')
//                     countO++;
//             }
//         }
//     }

//     //diagonal counting
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 5; ++j) {
//             bool flag = false;
//             if(j < 2){ //right diagonals only
//                 pair<int,int> l{i,j};
//                 pair<int,int> r{i+2,j+2};
//                 if(board[l.first][l.second] != board[r.first][r.second])
//                     break;
//                 l.first++;
//                 l.second++;
//                 while (l != r){
//                     if(board[l.first][l.second] != board[r.first][r.second])
//                         break;
//                     l.first++;
//                     l.second++;
//                     flag = true;
//                 }
//                 if(flag){
//                     if(board[r.first][r.second] == 'X')
//                         countX++;
//                     else if(board[r.first][r.second] == 'O')
//                         countO++;
//                 }

//             }
//             flag = false;
//             if(j >= 2){     //left diagonals
//                 pair<int,int> l{i,j};
//                 pair<int,int> r{i+2,j-2};
//                 if(board[l.first][l.second] != board[r.first][r.second])
//                     break;
//                 l.first++;
//                 l.second--;
//                 while (l != r){
//                     if(board[l.first][l.second] != board[r.first][r.second])
//                         break;
//                     l.first++;
//                     l.second--;
//                     flag = true;
//                 }
//                 if(flag){
//                     if(board[r.first][r.second] == 'X')
//                         countX++;
//                     else if(board[r.first][r.second] == 'O')
//                         countO++;
//                 }
//             }
//         }
//     }

//     if(symbol == 'X')
//         return countX;
//     else
//         return countO;
// }

// bool FivexFive_Tic_Tac_Toe::is_winner() {
//     if(!game_is_over())
//         return false;
//     int ansX = count_threes('X');
//     int ansO = count_threes('O');
//     if(ansX > ansO){
//         cout << "Player 1 wins\n";
//         return true;
//     }
//     if(ansX < ansO){
//         cout << "Player 2 wins\n";
//         return true;
//     }
//     return false;
// }

// bool FivexFive_Tic_Tac_Toe::is_draw() {
//     if(n_moves == 24 && !is_winner())
//         return true;
//     return false;
// }

// bool FivexFive_Tic_Tac_Toe::game_is_over() {
//     return n_moves >= 24;
// }
