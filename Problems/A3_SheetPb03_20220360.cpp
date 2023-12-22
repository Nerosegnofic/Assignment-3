// File name: A3_SheetPb03_20220360
// Purpose: solving problem 3 in sheet 2
// Author(s): Nour-aldeen Alaa Adel
// ID(s): 20220360
// Section: S24
// Date: 12/6/2023

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    map <string, int> m;
    string s,filename;
    cin >> filename;
    ifstream file(filename+".txt");

    if(!file.is_open())
        cerr << "error: can't open file!!";

    string word;
    while (!file.eof()){
        string targetWord = "";
        getline(file,word,' ');
        for (int i = 0; i < word.length(); ++i) {
            if(isalpha(word[i]) && !ispunct(word[i]))
                targetWord += tolower(word[i]);

        }
        m[targetWord]++;
    }
    for(auto i : m){
        cout << i.first << " " << i.second << '\n';
    }


}
