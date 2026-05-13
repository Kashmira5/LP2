#include <iostream>

using namespace std;

class NQueens {

    int board[10][10];
    int n;

    // Arrays for Branch and Bound
    bool column[10];
    bool diag1[20];
    bool diag2[20];

public:

    // Constructor
    NQueens(int size) {

        n = size;

        // Initialize board with 0
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                board[i][j] = 0;
            }
        }

        // Initialize helper arrays
        for(int i = 0; i < 10; i++) {
            column[i] = false;
        }

        for(int i = 0; i < 20; i++) {
            diag1[i] = false;
            diag2[i] = false;
        }
    }

    // Function to check safe position
    bool isSafe(int row, int col) {

        // Check column
        if(column[col])
            return false;

        // Check left diagonal
        if(diag1[row - col + n - 1])
            return false;

        // Check right diagonal
        if(diag2[row + col])
            return false;

        return true;
    }

    // Recursive Backtracking function
    bool solve(int row) {

        // If all queens placed
        if(row == n)
            return true;

        // Try each column
        for(int col = 0; col < n; col++) {

            // Check safe position
            if(isSafe(row, col)) {

                // Place queen
                board[row][col] = 1;

                // Mark column and diagonals
                column[col] = true;
                diag1[row - col + n - 1] = true;
                diag2[row + col] = true;

                // Recursive call for next row
                if(solve(row + 1))
                    return true;

                // Backtracking
                board[row][col] = 0;

                column[col] = false;
                diag1[row - col + n - 1] = false;
                diag2[row + col] = false;
            }
        }

        return false;
    }

    // Print board
    void printBoard() {

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << ". ";
            }

            cout << endl;
        }
    }
};

int main() {

    int n;

    cout << "Enter number of queens: ";
    cin >> n;

    NQueens q(n);

    // Solve problem
    if(q.solve(0)) {

        cout << "\nSolution Found:\n\n";

        q.printBoard();
    }
    else {

        cout << "No Solution Exists";
    }

    return 0;
}
