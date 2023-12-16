#include"../include/BoardGame_Classes.hpp"

using namespace std;

connectFourBoard::connectFourBoard() {
    n_rows = 6;
    n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool connectFourBoard::update_board(int x, int y, char mark) {
    // Only update if move is valid
    bool isValid = (x == 5 || board[x + 1][y] != 0);
    if (!(x < 0 || x > 5 || y < 0 || y > 6) && isValid && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        lst_x = x , lst_y = y ,lst_symbol = toupper(mark);
        return true;
    }
    else
        return false;
}

void connectFourBoard::display_board() {
    for (int i: {0, 1, 2 , 3 , 4 , 5}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6,}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

bool connectFourBoard::is_winner() {
// horizontally
    for(int i = max(0 , lst_y - 3) ; i <= min(lst_y , 3) ; ++i)
    {

        for(int j{i} ; j < i + 4 ; ++j)
        {
            if(board[lst_x][j] != lst_symbol)
            {
                goto dist1;
            }
        }
        return 1;
        dist1:;
    }
// vertically
    for(int i = max(0 , lst_x - 3) ; i <= min(lst_x , 2) ; ++i)
    {

        for(int j{i} ; j < i + 4 ; ++j)
        {
            if(board[j][lst_y] != lst_symbol)
            {
                goto dist2;
            }
        }
        return 1;
        dist2:;
    }
// diagonally
    for(int i = lst_x - min(lst_x , lst_y) , j = lst_y - min(lst_x , lst_y) ; i <= min(lst_x , 2) && j <= min(lst_y , 3) ; ++i , ++j)
    {
        for(int k{} ; k < 4 ; k++)
        {
            if(board[i + k][j + k] != lst_symbol)
            {
                goto dist3;
            }
        }
        return 1;
        dist3:;
    }

    for(int i = lst_x + min(5 - lst_x , lst_y) , j = lst_y - min(5 - lst_x , lst_y) ; i >= min(lst_x , 3) && j <= min(lst_y , 3) ; --i , ++j)
    {
        for(int k{} ; k < 4 ; k++)
        {
            if(board[i - k][j + k] != lst_symbol)
            {
                goto dist4;
            }
        }
        return 1;
        dist4:;
    }

    return 0;
}

bool connectFourBoard::is_draw() {
    return n_moves == 42 && !is_winner();
}

bool connectFourBoard::game_is_over() {
    return  n_moves == 42;
}


