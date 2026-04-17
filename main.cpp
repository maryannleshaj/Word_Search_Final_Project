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

       void fillRest() {
        for (int r = 0; r < size; ++r) { //cycles through rows
            for (int c = 0; c < size; ++c) { //cycles through columns
                if (grid[r][c] == '.') grid[r][c] = 'A' + (rand() % 26); //replaces dots with random letters
            }
        }
    }


    void display() {
        cout << "\n--- GENERATED WORD SEARCH ---\n";
        for (auto& row : grid) {
            for (char c : row) cout << c << " "; //prints each letter with a space
            cout << endl;
        }
    }

        void solve() {
        cout << "\n--- SOLVING ---\n";
        for (const string& word : wordList) { //goes through the list of words we added
            bool found = false;
            for (int r = 0; r < size && !found; ++r) { //scans every row
                for (int c = 0; c < size && !found; ++c) { //scans every column
                    if (grid[r][c] == word[0]) { //only starts looking if the first letter matches
                        for (int dir = 0; dir < 8; ++dir) {
                            int k, currR = r + dr[dir], currC = c + dc[dir];
                            for (k = 1; k < word.length(); ++k) { //checks the rest of the letters in that direction
                                if (currR < 0 || currR >= size || currC < 0 || currC >= size || grid[currR][currC] != word[k]) break;
                                currR += dr[dir]; currC += dc[dir]; //moves to the next spot in the direction
                            }
                            if (k == word.length()) { //if we found every letter in the word
                                cout << "Found '" << word << "' starting at row " << r << ", col " << c << "\n";
                                found = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
};




int main() {
    int s;
    cout << "Welcome to the Word Search Final Project!\n";
    cout << "Enter grid size (6 to 12): ";
    while (!(cin >> s) || s < 6 || s > 12) { //makes sure the user picks a good grid size
        cout << "Error: Size must be 6-12. Try again: ";
        cin.clear(); cin.ignore(1000, '\n');
    }


    WordSearch ws(s); //creates the wordsearch object
    ws.handleInputs(); //gets words from user
    ws.fillRest(); //fills blanks with random letters
    ws.display(); //shows the final grid
    ws.solve(); //shows where the words were hidden


    return 0;
}
