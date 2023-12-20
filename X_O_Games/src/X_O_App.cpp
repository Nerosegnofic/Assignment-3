// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include"../include/BoardGame_Classes.hpp"

void menu();

int main() {
    menu();

    return 0;

}

void menu() {
    int game_choice;
    cout << "What game do you want?" << '\n'
         << "1 - X O Game" << '\n'
         << "2 - Pyramic X O Game" << '\n'
         << "3 - Connect Four" << '\n'
         << "4 - 5 x 5 Tic Tac Toe" << endl;
    cin >> game_choice;
    while (game_choice < 1 || game_choice > 4) {
        cout << "Invalid Input. Try again" << endl;
        cin >> game_choice;
    }

    switch (game_choice) {
        case 1: {
            int choice1, choice2;
            char choice3;

            Player *players[2];
            players[0] = new Player(1, 'x');

            cout << "Welcome to FCAI X-O Game. :)\n";
            cout << "Press 1 if you want to play with computer: ";
            cin >> choice1;
            if (choice1 != 1) {
                players[1] = new Player(2, 'o');
            } else {
                //Player pointer points to child
                players[1] = new RandomPlayer('o', 3, 3);
            }

            GameManager X_O(new X_O_Board(), players);
            X_O.run();
            cout << "Do you want to play a game again? (Y/N)" << endl;
            cin >> choice3;
            while (toupper(choice3) != 'Y' && toupper(choice3) != 'N') {
                cout << "Invalid Input. Try again" << endl;
                cin >> choice3;
            }
            if (toupper(choice3) == 'Y') {
                menu();
            } else {
                system("pause");
            }
            break;
        }
        case 2: {
            int choice1, choice2;
            char choice3;

            Player *players[2];
            players[0] = new Player(1, 'x');

            cout << "Welcome to FCAI Pyramic X-O Game. :)\n";
            cout << "Press 1 if you want to play with computer: ";
            cin >> choice1;
            if (choice1 != 1) {
                players[1] = new Player(2, 'o');
            } else {
                //Player pointer points to child
                players[1] = new RandomPlayer('o', 3, 5);
            }

            GameManager pyramic_x_o_game(new Pyramic_X_O(), players);
            pyramic_x_o_game.run();
            cout << "Do you want to play a game again? (Y/N)" << endl;
            cin >> choice3;
            while (toupper(choice3) != 'Y' && toupper(choice3) != 'N') {
                cout << "Invalid Input. Try again" << endl;
                cin >> choice3;
            }
            if (toupper(choice3) == 'Y') {
                menu();
            } else {
                system("pause");
            }
            break;
        }
        case 3: {
            int choice1, choice2;
            char choice3;

            Player *players[2];
            players[0] = new Player(1, 'x');

            cout << "Welcome to FCAI Connect Four Game. :)\n";
            cout << "Press 1 if you want to play with computer: ";
            cin >> choice1;
            if (choice1 != 1) {
                players[1] = new Player(2, 'o');
            } else {
                //Player pointer points to child
                players[1] = new RandomPlayer('o', 6, 7);
            }

            GameManager connect_four (new connectFourBoard(), players);
            connect_four.run();
            cout << "Do you want to play a game again? (Y/N)" << endl;
            cin >> choice3;
            while (toupper(choice3) != 'Y' && toupper(choice3) != 'N') {
                cout << "Invalid Input. Try again" << endl;
                cin >> choice3;
            }
            if (toupper(choice3) == 'Y') {
                menu();
            } else {
                system("pause");
            }
            break;
        }
        case 4: {
            int choice1, choice2;
            char choice3;

            Player *players[2];
            players[0] = new Player(1, 'x');

            cout << "Welcome to FCAI 5x5 X-O Game. :)\n";
            cout << "Press 1 if you want to play with computer: ";
            cin >> choice1;
            if (choice1 != 1) {
                players[1] = new Player(2, 'o');
            } else {
                //Player pointer points to child
                players[1] = new RandomPlayer('o', 5, 5);
            }

            GameManager_5x5 FivexFive(new FivexFive_Tic_Tac_Toe(), players);
            FivexFive.run();
            cout << "Do you want to play a game again? (Y/N)" << endl;
            cin >> choice3;
            while (toupper(choice3) != 'Y' && toupper(choice3) != 'N') {
                cout << "Invalid Input. Try again" << endl;
                cin >> choice3;
            }
            if (toupper(choice3) == 'Y') {
                menu();
            } else {
                system("pause");
            }
            break;
        }
    }
}
