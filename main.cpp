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

    bool canPlace(const string& word, int r, int c, int dir) { //this function checks if the spot on the wordsearch is a good fit for a character
        for (int i = 0; i < word.length(); ++i) {
            int nr = r + i * dr[dir]; //this makes the code go to a random direction to place the next word
            int nc = c + i * dc[dir];
            if (nr < 0 || nr >= size || nc < 0 || nc >= size) return false; //stops the code from going off the grid
            if (grid[nr][nc] != '.' && grid[nr][nc] != word[i]) return false; //checks if the spot is already taken by a different letter
        }
        return true;
    }


    bool placeWord(const string& word) {
        int attempts = 0;
        while (attempts < 150) { // Try 150 times to find a fit
            int r = rand() % size; //picks a random starting row
            int c = rand() % size; //picks a random starting column
            int dir = rand() % 8; //picks one of the 8 directions randomly


            if (canPlace(word, r, c, dir)) { //if the spot is good it actually puts the letters in
                for (int i = 0; i < word.length(); ++i) {
                    grid[r + i * dr[dir]][c + i * dc[dir]] = word[i];
                }
                return true;
            }
            attempts++; //keeps track of how many times we tried to fit the word
        }
        return false;
    }

public:
    WordSearch(int s) : size(s) {
        srand(time(0)); //makes the random numbers different every time you run it
        grid.resize(size, vector<char>(size, '.')); //sets up the grid and fills it with dots
        maxWords = s / 1.5 + 1; // calculation: max words is roughly size/1.5 
    }
};

