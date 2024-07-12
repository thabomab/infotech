#include <iostream>
#include <string>
#define SIZE 9

using namespace std;

void printGrid(int grid[SIZE][SIZE]);
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num);
bool solveSudoku(int grid[SIZE][SIZE]);
bool findEmptyLocation(int grid[SIZE][SIZE], int &row, int &col);
bool usedInRow(int grid[SIZE][SIZE], int row, int num);
bool usedInCol(int grid[SIZE][SIZE], int col, int num);
bool usedInBox(int grid[SIZE][SIZE], int boxStartRow, int boxStartCol, int num);
void inputGrid(int grid[SIZE][SIZE]);

int main() {
    int grid[SIZE][SIZE];

    cout << "Enter the Sudoku puzzle row by row as 9-digit numbers (use 0 for empty cells):" << endl;
    inputGrid(grid);

    if (solveSudoku(grid)) {
        printGrid(grid);
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}

void inputGrid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        string line;
        cout << "row " << row + 1 << " (use 0 for empty cells): ";
        cin >> line;
        for (int col = 0; col < SIZE; col++) {
            grid[row][col] = line[col] - '0';
        }
    }
}

void printGrid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    return !usedInRow(grid, row, num) &&
           !usedInCol(grid, col, num) &&
           !usedInBox(grid, row - row % 3, col - col % 3, num);
}

bool solveSudoku(int grid[SIZE][SIZE]) {
    int row, col;

    if (!findEmptyLocation(grid, row, col)) {
        return true; // puzzle solved
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) {
                return true;
            }

            grid[row][col] = 0; // backtrack
        }
    }

    return false; // triggers backtracking
}

bool findEmptyLocation(int grid[SIZE][SIZE], int &row, int &col) {
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool usedInRow(int grid[SIZE][SIZE], int row, int num) {
    for (int col = 0; col < SIZE; col++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool usedInCol(int grid[SIZE][SIZE], int col, int num) {
    for (int row = 0; row < SIZE; row++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool usedInBox(int grid[SIZE][SIZE], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + boxStartRow][col + boxStartCol] == num) {
                return true;
            }
        }
    }
    return false;
}

