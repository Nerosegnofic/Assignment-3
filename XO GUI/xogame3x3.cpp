#include "xogame3x3.h"
#include "ui_xogame3x3.h"
#include "QGridLayout.h"
#include "QPushButton.h"
#include "BoardGame_Classes.h"
#include <QMessageBox>

XOGame3x3::XOGame3x3(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::XOGame3x3)
{
    ui->setupUi(this);
    QGridLayout *gridLayout = new QGridLayout(this);
    board3x3 = new X_O_Board();

    for (int i {0}; i < 3; ++i) {
        for (int j {0}; j < 3; ++j) {

            QPushButton *button = new QPushButton(this);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            isAlternated = true;
            gridLayout->addWidget(button, i, j);
            connect(button, &QPushButton::clicked, [=](){
                if (isAlternated && board3x3->board[i][j] == 0) {
                    button->setText("X");
                    board3x3->board[i][j] = 'X';
                    isAlternated = false;
                    ++n_moves;
                } else if (!isAlternated && board3x3->board[i][j] == 0){
                    button->setText("O");
                    board3x3->board[i][j] = 'O';
                    isAlternated = true;
                    ++n_moves;
                }

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
                } else if (n_moves == 9 && !isWinner(i, j)) {
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

bool XOGame3x3::isWinner(int i, int j) {
    char row_win[3], col_win[3], diag_win[2];
    for (int i:{0,1,2}) {
        row_win[i] = board3x3->board[i][0] & board3x3->board[i][1] & board3x3->board[i][2];
        col_win[i] = board3x3->board[0][i] & board3x3->board[1][i] & board3x3->board[2][i];
    }
    diag_win[0] = board3x3->board[0][0] & board3x3->board[1][1] & board3x3->board[2][2];
    diag_win[1] = board3x3->board[2][0] & board3x3->board[1][1] & board3x3->board[0][2];

    for (int i:{0,1,2}) {
        if ( (row_win[i] && (row_win[i] == board3x3->board[i][0])) ||
            (col_win[i] && (col_win[i] == board3x3->board[0][i])) )
        {return true;}
    }
    if ((diag_win[0] && diag_win[0] == board3x3->board[1][1]) ||
        (diag_win[1] && diag_win[1] == board3x3->board[1][1]))
    {return true;}
    return false;
}


XOGame3x3::~XOGame3x3()
{

    delete ui;
}
