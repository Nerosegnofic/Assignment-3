#ifndef XOGAME3X3_H
#define XOGAME3X3_H

#include <QDialog>
#include "BoardGame_Classes.h"

namespace Ui {
class XOGame3x3;
}

class XOGame3x3 : public QDialog
{
    Q_OBJECT

public:
    explicit XOGame3x3(QWidget *parent = nullptr);
    bool isWinner(int, int);
    ~XOGame3x3();

private:
    int n_moves {0};
    X_O_Board *board3x3;
    bool isAlternated;
    Ui::XOGame3x3 *ui;
};

#endif // XOGAME3X3_H
