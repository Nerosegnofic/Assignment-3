#include "xogame5x5.h"
#include "ui_xogame5x5.h"
#include "QGridLayout.h"
#include "QPushButton.h"
#include "BoardGame_Classes.h"
#include <QMessageBox>

xogame5x5::xogame5x5(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::xogame5x5)
{
    ui->setupUi(this);
    QGridLayout *gridLayout = new QGridLayout(this);
    createBoard();

    for (int i {0}; i < 5; ++i) {
        for (int j {0}; j < 5; ++j) {

            QPushButton *button = new QPushButton(this);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            isAlternated = true;
            gridLayout->addWidget(button, i, j);
            connect(button, &QPushButton::clicked, [=](){
                if (isAlternated && board5x5[i][j] == 0) {
                    button->setText("X");
                    board5x5[i][j] = 'X';
                    isAlternated = false;
                    ++n_moves;
                } else if (!isAlternated && board5x5[i][j] == 0){
                    button->setText("O");
                    board5x5[i][j] = 'O';
                    isAlternated = true;
                    ++n_moves;
                }

                if (n_moves == 24) {
                if (isWinner(i, j)) {
                    QMessageBox msgBox;
                    QPushButton *okayButton;
                    msgBox.setWindowTitle("ATTENTION");
                    okayButton = msgBox.addButton("OK", QMessageBox::ActionRole);
                    if (!isAlternated) {
                        msgBox.setText("X wins!");
                    } else {
                        msgBox.setText("O wins!");
                    }
                    msgBox.exec();
                    close();
                } else {
                    QMessageBox msgBox;
                    QPushButton *okayButton;
                    msgBox.setWindowTitle("ATTENTION");
                    okayButton = msgBox.addButton("OK", QMessageBox::ActionRole);
                    msgBox.setText("Draw!");
                    msgBox.exec();
                    close();

                }
            }});
        }
    }
}

int xogame5x5::countThrees(char symbol) {

        int countX = 0, countO = 0;
        //horizontal counting
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 3; ++j) {
                bool flag = false;
                int l = j, r = j+2;
                if(board5x5[i][l] != board5x5[i][r])
                    continue;
                l++;
                while (l != r){
                    if(board5x5[i][l] != board5x5[i][r])
                        break;
                    l++;
                    flag = true;
                }
                if(flag) {
                    if (board5x5[i][r] == 'X')
                        countX++;
                    if (board5x5[i][r] == 'O')
                        countO++;
                }
            }
        }
        //vertical counting
        for (int col = 0; col < 5; ++col) {
            for (int row = 0; row < 3; ++row) {
                bool flag = false;
                int l=row, r=row+2;
                if(board5x5[l][col] != board5x5[r][col])
                    continue;
                l++;
                while (l != r){
                    if(board5x5[l][col] != board5x5[r][col])
                        break;
                    l++;
                    flag = true;
                }
                if(flag) {
                    if (board5x5[r][col] == 'X')
                        countX++;
                    if (board5x5[r][col] == 'O')
                        countO++;
                }
            }
        }

        //diagonal counting
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                bool flag = false;
                if(j < 2){ //right diagonals only
                    pair<int,int> l{i,j};
                    pair<int,int> r{i+2,j+2};
                    if(board5x5[l.first][l.second] != board5x5[r.first][r.second])
                        break;
                    l.first++;
                    l.second++;
                    while (l != r){
                        if(board5x5[l.first][l.second] != board5x5[r.first][r.second])
                            break;
                        l.first++;
                        l.second++;
                        flag = true;
                    }
                    if(flag){
                        if(board5x5[r.first][r.second] == 'X')
                            countX++;
                        else if(board5x5[r.first][r.second] == 'O')
                            countO++;
                    }

                }
                flag = false;
                if(j >= 2){     //left diagonals
                    pair<int,int> l{i,j};
                    pair<int,int> r{i+2,j-2};
                    if(board5x5[l.first][l.second] != board5x5[r.first][r.second])
                        break;
                    l.first++;
                    l.second--;
                    while (l != r){
                        if(board5x5[l.first][l.second] != board5x5[r.first][r.second])
                            break;
                        l.first++;
                        l.second--;
                        flag = true;
                    }
                    if(flag){
                        if(board5x5[r.first][r.second] == 'X')
                            countX++;
                        else if(board5x5[r.first][r.second] == 'O')
                            countO++;
                    }
                }
            }
        }

        if(symbol == 'X')
            return countX;
        else
            return countO;
}


bool xogame5x5::isWinner(int i, int j) {
    if(!game_is_over())
        return false;
    int ansX = countThrees('X');
    int ansO = countThrees('O');
    if(ansX > ansO){
        cout << "Player 1 wins\n";
        return true;
    }
    if(ansX < ansO){
        cout << "Player 2 wins\n";
        return true;
    }
    return false;

}

bool xogame5x5::is_draw(int i, int j) {
    if(n_moves == 24 && !isWinner(i, j))
        return true;
    return false;
}

bool xogame5x5::game_is_over() {
    return n_moves >= 24;
}

xogame5x5::~xogame5x5()
{
    delete ui;
}
