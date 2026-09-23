#include <iostream>
#include <vector>

#define N 9

void printGrid(const int grid[N][N]) {
    for (int r = 0; r < N; ++r) {
        if (r % 3 == 0 && r != 0) {
            std::cout << "---------------------\n";
        }
        for (int c = 0; c < N; ++c) {
            if (c % 3 == 0 && c != 0) {
                std::cout << "| ";
            }
            std::cout << grid[r][c] << " ";
        }
        std::cout << "\n";
    }
}

bool isValid(const int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; ++x) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int grid[N][N], int row = 0, int col = 0) {
    if (row == N - 1 && col == N) {
        return true;
    }

    if (col == N) {
        row++;
        col = 0;
    }

    if (grid[row][col] > 0) {
        return solveSudoku(grid, row, col + 1);
    }

    for (int num = 1; num <= N; ++num) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid, row, col + 1)) {
                return true;
            }

            grid[row][col] = 0; // Backtrack
        }
    }

    return false;
}

int main() {
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    std::cout << "=== Original Sudoku Grid ===\n";
    printGrid(grid);

    if (solveSudoku(grid)) {
        std::cout << "\n=== Solved Sudoku Grid ===\n";
        printGrid(grid);
    } else {
        std::cout << "\nNo solution exists for the given Sudoku grid.\n";
    }

    return 0;
}
