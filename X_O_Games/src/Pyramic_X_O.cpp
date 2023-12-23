// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

// Class definition for Pyramic_X_O class
// Author:  Ahmed Abdelnabi
// Date:    12/11/2023
// Version: 1

#include "../include/BoardGame_Classes.hpp"


Pyramic_X_O::Pyramic_X_O() {
    board = new char*;
    board[0] = new char[9];
    n_rows = 1;
    n_cols = 9;
    for (int j {0}; j < 9; ++j) {
        board[0][j] = ' ';
    }
}

bool Pyramic_X_O::update_board(int x, int y, char mark){
    int position;

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
    } else {
        return false;
    }
    // Only update if move is valid
    if (board[0][position - 1] == ' ') {
        board[0][position - 1] = toupper(mark);
        ++n_moves;
        return true;
    }
    return false;
}

void Pyramic_X_O::display_board() {
    cout << "                  I(0, 0) " << board[0][0] << 'I' << endl;
    cout << "                  ----------" << endl;
    cout << "         I(1, 0) " << board[0][1] << "I(1, 1) " << board[0][2] << "I(1, 2) " << board[0][3] << 'I' <<  endl;
    cout << "         ----------------------------" << endl;
    cout << "I(2, 0) " << board[0][4] << "I(2, 1) " << board[0][5] << "I(2, 2) " << board[0][6] << "I(2, 3) " << board[0][7] << "I(2, 4) " << board[0][8] << 'I' << endl;
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

AI_Pyramid_X_O_Player::AI_Pyramid_X_O_Player(char symbol, Board* board) : Player(symbol)
{
    this->name = "AI  Player";
    cout << "My names is " << name << endl;
    boardptr = board;
}

string AI_Pyramid_X_O_Player::board_to_string(vector<string>board) {
    string ret = "";

    for(int i{}; i < boardptr->get_n_rows(); ++i)
        for(int j{}; j < boardptr->get_n_cols(); ++j)
            ret += (!board[i][j])? '_':board[i][j];
    return ret;

}
map<string, int>dp2;

int AI_Pyramid_X_O_Player::minimax(vector<string>board,int depth, int alpha, int beta, bool maximizer) {

    string state = board_to_string(board);
//        cout << depth<<' '<<alpha<<' '<<beta<<' '<<maximizer<<' '<<state<<' '<< evaluate(board, maximizer? 'X' : 'O')<<'\n';
    if(dp2.find(state) != dp2.end()) {
        return dp2[state];
    }
    if(!depth)
    {

    }

    if(maximizer)
    {
        int max_value{-(int)1e9};
        for(int i{}; i < boardptr->get_n_rows(); ++i)
        {
            for(int j{}; j < boardptr->get_n_cols(); ++j)
            {
                if(!board[i][j])
                {
                    vector<string> temp_board = board;  // Create a deep copy
                    temp_board[i][j] = 'O';
                    int value = minimax(temp_board,depth - 1, alpha, beta, 0);
                    max_value = max(value , max_value);
                    alpha = max(alpha, value);
//                  board[i][j] = 0;
                    if(beta <= alpha)
                        break;
                }

            }
        }
        return dp2[state] = max_value;
    }
    else
    {
        int min_value{(int)1e9};
        for(int i{}; i < boardptr->get_n_rows(); ++i)
        {
            for(int j{}; j < boardptr->get_n_cols(); ++j)
            {
                if(!board[i][j])
                {
                    vector<string> temp_board = board;  // Create a deep copy
                    temp_board[i][j] = 'X';
                    int value = minimax(temp_board,depth - 1, alpha, beta, 1);
                    min_value = min(value , min_value);
                    beta = min(beta, value);
                    if(beta <= alpha)
                        break;
                }
            }
        }
        return dp2[state] = min_value;
    }
}

void AI_Pyramid_X_O_Player::get_move(int &x, int &y, bool maximizer) {

    int max_eval = -(int)1e9;
    char symbol = (maximizer)? 'O' : 'X';
    vector<string>temp_board = boardptr->get_board();

//  for(auto i : dp2)cout<<i.first<<' '<<i.second<<'\n';
    for(int i{}; i < boardptr->get_n_rows(); ++i)
    {
        for(int j{}; j < boardptr->get_n_cols(); ++j)
        {
//            cout << max_eval<<'\n';
            if(!temp_board[i][j] ){
                temp_board[i][j] = 'O';
                int score = minimax(temp_board ,7,-1e9,1e9,false);
//                cout << score<<'\n';
                temp_board[i][j] = 0;
                if(score > max_eval){
                    max_eval = score;
                    x = i;
                    y = j;
                }
            }

        }
    }

}

void AI_Pyramid_X_O_Player::get_move(int &x, int &y) {
    get_move(x, y , 1);

}

