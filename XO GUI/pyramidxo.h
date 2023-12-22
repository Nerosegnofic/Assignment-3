#ifndef PYRAMIDXO_H
#define PYRAMIDXO_H

#include <QDialog>
#include "BoardGame_Classes.h"

namespace Ui {
class PyramidXO;
}

class PyramidXO : public QDialog
{
    Q_OBJECT

public:
    explicit PyramidXO(QWidget *parent = nullptr);
    void createBoard() {
        board3x5 = new char*[3];
        for (int i = 0; i < 3; i++) {
            board3x5[i] = new char[5];
            for (int j = 0; j < 5; j++)
                board3x5[i][j] = 0;
        }
    }

    bool isWinner();
    ~PyramidXO();

private:
    int n_moves {0};
    char **board3x5;
    bool isAlternated;
    bool game_is_over();
    bool is_draw(int i, int j);
    Ui::PyramidXO *ui;
};

#endif // PYRAMIDXO_H
