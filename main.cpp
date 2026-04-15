#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

class WordSearch {
private:
    int size;
    int maxWords; // added to prevent "impossible" grids
    vector<vector<char>> grid; //stores the "grid" of characters
    vector<string> wordList; //stores the words the user inputs

    const int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; //these tell the code which direction to go, dr for delta row dc for delta column
    const int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1}; //0 for staying in place, 1 for moving forward/up, and -1 for back/down

    string toUpper(string s) { //changes the characters in the word the user inputs to uppercase
        for (auto &c : s) c = toupper(c); //for loop using toupper() to change each character to uppercase. the & symbol stores it in memory
        return s;
    }

public:
    WordSearch(int s) : size(s) {
        srand(time(0)); //makes the random numbers different every time you run it
        grid.resize(size, vector<char>(size, '.')); //sets up the grid and fills it with dots
        maxWords = s / 1.5 + 1; // calculation: max words is roughly size/1.5 
    }
};

