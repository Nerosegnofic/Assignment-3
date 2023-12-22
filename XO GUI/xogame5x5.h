#ifndef XOGAME5X5_H
#define XOGAME5X5_H

#include <QDialog>
#include "BoardGame_Classes.h"

namespace Ui {
class xogame5x5;
}

class xogame5x5 : public QDialog
{
    Q_OBJECT

public:
    explicit xogame5x5(QWidget *parent = nullptr);
    void createBoard() {
            board5x5 = new char*[5];
            for (int i = 0; i < 5; i++) {
                board5x5[i] = new char[5];
                for (int j = 0; j < 5; j++)
                    board5x5[i][j] = 0;
            }
    }

    bool isWinner(int, int);
    int countThrees(char);

    ~xogame5x5();

private:
    int n_moves {0};
    char **board5x5;
    bool isAlternated;
    bool game_is_over();
    bool is_draw(int i, int j);
    Ui::xogame5x5 *ui;
};

#endif // XOGAME3X3_H
