// File name: A3_SheetPb03_20220360
// Purpose: solving problem 3 in sheet 2
// Author(s): Nour-aldeen Alaa Adel
// ID(s): 20220360
// Section: S24
// Date: 12/7/2023

#include <iostream>
#include <bits/stdc++.h>
#include <random>
using namespace std;
const int SIZE = 20;
class Universe{
private:
    bool grid[SIZE+2][SIZE+2], tmp[SIZE + 2][SIZE + 2];
public:
    Universe(){
        reset();
        initialize();
    }
    void initialize(){
        std::mt19937 rng(std::random_device{}());
        uniform_int_distribution<int> dist(1,10);
        for (int i = 1; i < SIZE+1; ++i) {
            for (int j = 1; j < SIZE+1; ++j) {
                int random = dist(rng);
                if(random == 2 || random == 3)
                    grid[i][j] = 1;
                if(random < 2 || random > 3)
                    grid[i][j] = 0;
            }
        }

    }
    void reset(){
        for (int i = 0; i < SIZE+2; ++i) {
            for (int j = 0; j < SIZE+2; ++j) {
                grid[i][j] = 0;
            }
        }
    }
    int count_neighbours(int row, int col){
        int count = 0;
        //iterate over the neighbors of grid[row][col] which are forming a square with 3 rows and 3 columns
        for(int i = row - 1; i < row+2; ++i){
            for (int j = col-1; j < col+2; ++j) {
                if(tmp[i][j])
                    count++;
            }
        }
        return count;
    }
    void next_generation(){
        for (int i = 0; i < SIZE+2; ++i) {
            for (int j = 0; j < SIZE+2; ++j) {
                tmp[i][j] = grid[i][j];
            }
        }
        for (int i = 1; i < SIZE + 1; ++i) {
            for (int j = 1; j < SIZE+1; ++j) {
                int Neighbors = count_neighbours(i,j);
                //check for dead cells
                if(!tmp[i][j] && Neighbors == 3){
                    grid[i][j] = 1;
                }

                //live cells that gets dead condition
                //notice that we incremented the conditions by 1 because as we
                //iterate to count the neighbors, we count the cell that we're in as well
                if(tmp[i][j] && (Neighbors < 3 || Neighbors > 4))
                    grid[i][j] = 0;

            }
        }
    }

    void display(){
        for (int i = 1; i < SIZE+1; ++i) {
            for (int j = 1; j < SIZE+1; ++j) {
                cout << grid[i][j] << " ";
            }
            cout << '\n';
        }
        cout << '\n' << "----------------------------------------------------" << '\n';
    }

    void run(int turns){
        cout << "Initial condition:\n";
        display();
        while (turns--){
            next_generation();
            display();
        }
    }
};

int main(){
    int turns;
    Universe game;
    cin >> turns;
    game.run(turns);
}
