#include <iostream>
using namespace std;

const int SIZE = 9;
char board[SIZE][SIZE];

// Function that prints the board on the screen
void printBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

// Function that places the player's move on the board
bool makeMove(int player, int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != '.') {
        return false;
    }

    board[row][col] = (player == 1) ? 'X' : 'O';
    return true;
}

// Function to check whether the game is over or not
bool checkWin(char player) {
    //Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE - 4; ++j) {
            // 5-way control in rows
            if (board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player &&
                board[i][j + 3] == player && board[i][j + 4] == player) {
                return true;
            }
            // 5-fold control in columns
            if (board[j][i] == player && board[j + 1][i] == player && board[j + 2][i] == player &&
                board[j + 3][i] == player && board[j + 4][i] == player) {
                return true;
            }
        }
    }

    // Check diagonals
    for (int i = 0; i < SIZE - 4; ++i) {
        for (int j = 0; j < SIZE - 4; ++j) {
            //Cross right down
            if (board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player &&
                board[i + 3][j + 3] == player && board[i + 4][j + 4] == player) {
                return true;
            }
            //Cross left down
            if (board[i][j + 4] == player && board[i + 1][j + 3] == player && board[i + 2][j + 2] == player &&
                board[i + 3][j + 1] == player && board[i + 4][j] == player) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    // initialize the board
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = '.';
        }
    }

    int player = 1;
    bool win = false;
    int moves = 0;

    while (!win && moves < SIZE * SIZE) {
        printBoard();
        int row, col;
        cout << "Player " << player << "'s turn. Enter row and column (0-8): ";
        cin >> row >> col;

        if (makeMove(player, row, col)) {
            win = checkWin((player == 1) ? 'X' : 'O');
            if (win) {
                printBoard();
                cout << "Player " << player << " wins!" << endl;
            }
            player = (player == 1) ? 2 : 1;
            moves++;
        }
        else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    if (!win) {
        printBoard();
        cout << "It's a draw!" << endl;
    }

    return 0;
}
