// Class definition for XO_SmartPlayer class
// Which is a computer player playing optimal moves
// Author:  Ahmed Abdelnabi
// Date:    10/10/2023
// Version: 1

#include<iostream>
#include"../include/BoardGame_Classes.hpp"

using namespace std;

SmartPlayer::SmartPlayer(char symbol): Player{symbol}{
    this->name = "AI Computer Player";
    cout << "My names is " << name << endl;
}

void SmartPlayer::get_move(int &x, int &y) {
    int position {0};
    if (x == 0 && y == 0) {
        position = 1;
    } else if (x == 1 && y == 0) {
        position = 2;
    } else if (x == 1 && y == 1) {
        position = 3;
    } else if (x == 1 && y == 2) {
        position = 4;
    } else if (x == 2 && y == 0) {
        position = 5;
    } else if (x == 2 && y == 1) {
        position = 6;
    } else if (x == 2 && y == 2) {
        position = 7;
    } else if (x == 2 && y == 3) {
        position = 8;
    } else if (x == 2 && y == 4) {
        position = 9;
    }
}