#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "xogame3x3.h"
#include <chrono>
#include <thread>
#include "QDebug"
#include "xogame5x5.h"
#include "pyramidxo.h"
#include "connectfour.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_XO_Button_clicked()
{
    XOGame3x3 xogame3x3;
    xogame3x3.setModal(true);
    xogame3x3.exec();

}

void MainWindow::on_FiveXO_Button_clicked()
{
    xogame5x5 xogame_5x5;
    xogame_5x5.setModal(true);
    xogame_5x5.exec();
}


void MainWindow::on_PyramicXO_Button_clicked()
{
    PyramidXO pyramidxo;
    pyramidxo.setModal(true);
    pyramidxo.exec();
}


void MainWindow::on_ConnectFour_Button_clicked()
{
    connectfour connectFour;
    connectFour.setModal(true);
    connectFour.exec();

}

