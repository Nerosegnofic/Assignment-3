#include "connectfour.h"
#include "ui_connectfour.h"
#include "QGridLayout.h"
#include "QPushButton.h"
#include "BoardGame_Classes.h"
#include <QMessageBox>

connectfour::connectfour(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::connectfour)
{
    ui->setupUi(this);
    QGridLayout *gridLayout = new QGridLayout(this);

    createBoard();

    for (int i {0}; i < 6; ++i) {
        for (int j {0}; j < 7; ++j) {

            QPushButton *button = new QPushButton(this);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            isAlternated = true;
            gridLayout->addWidget(button, i, j);
            connect(button, &QPushButton::clicked, [=](){
                if (isAlternated && update_board(i, j, 'X')) {
                    button->setText("X");
                    board6x7[i][j] = 'X';
                    isAlternated = false;
                    ++n_moves;
                } else if (!isAlternated && update_board(i, j, 'O')){
                    button->setText("O");
                    board6x7[i][j] = 'O';
                    isAlternated = true;
                    ++n_moves;
                }
                if (isWinner()) {
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
                } else if (n_moves == 42 && !isWinner()) {
                    QMessageBox msgBox;
                    QPushButton *okayButton;
                    msgBox.setWindowTitle("ATTENTION");
                    okayButton = msgBox.addButton("OK", QMessageBox::ActionRole);
                    msgBox.setText("Draw!");
                    msgBox.exec();
                    close();
                }
            });
        }
    }
}

bool connectfour::isWinner() {
    // horizontally
    for(int i = max(0 , lst_y - 3) ; i <= min(lst_y , 3) ; ++i)
    {

        for(int j{i} ; j < i + 4 ; ++j)
        {
            if(board6x7[lst_x][j] != lst_symbol)
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
            if(board6x7[j][lst_y] != lst_symbol)
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
            if(board6x7[i + k][j + k] != lst_symbol)
            {
                goto dist3;
            }
        }
        return 1;
    dist3:;
    }

    for(int i = lst_x + min(5 - lst_x , lst_y) , j = lst_y - min(5 - lst_x , lst_y) ; i >= max(lst_x , 3) && j <= min(lst_y , 3) ; --i , ++j)
    {
        for(int k{} ; k < 4 ; k++)
        {
            if(board6x7[i - k][j + k] != lst_symbol)
            {
                goto dist4;
            }
        }
        return 1;
    dist4:;
    }

    return 0;
}

bool connectfour::update_board(int x, int y, char mark) {
    // Only update if move is valid

    if (!(x < 0 || x > 5 || y < 0 || y > 6) && (board6x7[x][y] == 0)) {
        bool isValid = (x == 5 || board6x7[x + 1][y] != 0);
        if (isValid) {

            board6x7[x][y] = mark;
            lst_x = x , lst_y = y ,lst_symbol = mark;
            return true;
        } else {
            return false;
        }
    }
    else
        return false;
}

connectfour::~connectfour()
{
    delete ui;
}
