#include "pyramidxo.h"
#include "ui_pyramidxo.h"
#include "QGridLayout.h"
#include "QPushButton.h"
#include "BoardGame_Classes.h"
#include <QMessageBox>

PyramidXO::PyramidXO(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PyramidXO)
{
    ui->setupUi(this);
    QGridLayout *gridLayout = new QGridLayout(this);
    createBoard();

    for (int i {0}; i < 3; ++i) {
        for (int j {0}; j < 5; ++j) {

            QPushButton *button = new QPushButton(this);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            isAlternated = true;
            if ((i == 0 && j == 2) || (i == 1 && j == 1) || (i == 1 && j == 2) || (i == 1 && j == 3) || (i == 2 && j == 0) || (i == 2 && j == 1) || (i == 2 && j == 2) || (i == 2 && j == 3) || (i == 2 && j == 4)) {
            gridLayout->addWidget(button, i, j);
            connect(button, &QPushButton::clicked, [=](){
                if (isAlternated && board3x5[i][j] == 0) {
                    button->setText("X");
                    board3x5[i][j] = 'X';
                    isAlternated = false;
                    ++n_moves;
                } else if (!isAlternated && board3x5[i][j] == 0){
                    button->setText("O");
                    board3x5[i][j] = 'O';
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
                    } else if (n_moves == 9 && !isWinner()) {
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
}

bool PyramidXO::isWinner() {
    // Check for diagonals
    if ((board3x5[0][2] == board3x5[1][1] && board3x5[1][1] == board3x5[2][0] && board3x5[0][2] != 0) || (board3x5[0][2] == board3x5[1][3] && board3x5[1][3] == board3x5[2][4]) && board3x5[0][2] != 0) {
        return true;
        // Check for horizontals
    } else if (((board3x5[1][1] == board3x5[1][2] && board3x5[1][2] == board3x5[1][3]) && board3x5[1][1] != 0) || ((board3x5[2][0] == board3x5[2][1] && board3x5[2][1] == board3x5[2][2]) && board3x5[2][0] != 0) || ((board3x5[2][2] == board3x5[2][3] && board3x5[2][3] == board3x5[2][4]) && board3x5[2][2] != 0)  || ((board3x5[2][1] == board3x5[2][2] && board3x5[2][2] == board3x5[2][3])  && board3x5[2][1] != 0)) {
        return true;
        // Check for verticals
    } else if ((board3x5[0][2] == board3x5[1][2] && board3x5[1][2] == board3x5[2][2]) && board3x5[0][2] != 0) {
        return true;
    }
    return false;
}

PyramidXO::~PyramidXO()
{
    delete ui;
}
