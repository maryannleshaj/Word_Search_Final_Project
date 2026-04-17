# Word Search Generator and Solver

## Project Overview
This is a C++ command-line tool developed for **EECE 2140**. It generates randomized word search puzzles based on user-defined dimensions and word lists.

## Features
* **Custom Grids:** Supports variable square grid sizes.
* **8-Directional Search:** Words are placed using a directional offset algorithm.
* **Automatic Noise:** Empty spaces are filled with random characters.
* **Solution Key:** Outputs the starting coordinates for all successfully placed words.

## How to Run
1. **Compile the code:**
   Input: ` g++ main.cpp -o main_program ` in your command window.
2. **Run the code:**
   Input: ` ./main_program ` in your command window.
3. **Input your desired size and words:**
   Input the size of your grid when prompted, then input how many words you want, and each word youd like to hide one by one.
4. **Admire your wordsearch:**
   After that, your wordsearch with your chosen words and solutions will display. Thank you for using our program!

`Columns start from left to right. Rows start from top to bottom. Start counting from 0!`

*EXAMPLE USAGE*

**Input**
g++ main.cpp -o main_program
./main_program

**Output**
Welcome to the Word Search Final Project!
Enter grid size (6 to 12): 8
For a 8x8 grid, you can add up to 6 words.
How many words would you like to add? 1
Enter word 1: cat

--- GENERATED WORD SEARCH ---
L Q V N J T P V 
O V C A T N J A 
W I C D N C S E 
E Y V M D R I S 
B Z E S U T D N 
I Y B D N N G K 
V K P K O H P T 
I M F L D O E G 

--- SOLVING ---
Found 'CAT' starting at row 1, col 2


**Contributors:**
Maryann Leshaj
Waleska Lopez