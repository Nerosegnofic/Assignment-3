#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H

#include <QDialog>
#include "BoardGame_Classes.h"

namespace Ui {
class connectfour;
}

class connectfour : public QDialog
{
    Q_OBJECT

public:
    explicit connectfour(QWidget *parent = nullptr);
    void createBoard() {
        board6x7 = new char*[6];
        for (int i = 0; i < 6; i++) {
            board6x7[i] = new char[7];
            for (int j = 0; j < 7; j++)
                board6x7[i][j] = 0;
        }
    }
    bool isWinner();
    bool update_board(int, int, char);
    ~connectfour();

private:
    int lst_x ,lst_y;
    char lst_symbol;
    int n_moves {0};
    char **board6x7;
    bool isAlternated;
    Ui::connectfour *ui;
};

#endif // CONNECTFOUR_H
