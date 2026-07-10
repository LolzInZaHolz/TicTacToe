#include <iostream>
#include <cstdlib>   // Needed for rand() and srand()
#include <ctime>     // Needed for time() to seed the random generator
#include <thread> // Needed for sleeping
#include <chrono> // Needed for time units (seconds)
using namespace std;


    // Global constant defining the dimensions of the square board
    const int SIZE = 3;

    // A 2D array of characters acting as the game board
    char board[SIZE][SIZE];

    // Clears the board by filling every cell with an empty space character ' '
    void initializeBoard() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = ' ';
            }
        }
    }

    // Renders the current state of the board onto the console
    void printBoard() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cout << board[i][j];
                // Prints vertical dividers between columns
                if (j < SIZE - 1) cout << " | ";
            }
            cout << endl;
            // Prints horizontal dividers between rows
            if (i < SIZE - 1) cout << "---------" << endl;
        }
    }

    // Checks if the specified player ('X' or 'O') has won the game
    bool isWinner(char player) {
        // Loop to check all rows and columns simultaneously
        for (int i = 0; i < SIZE; i++) {
            // Horizontal win check
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
            // Vertical win check
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
        }
        // Main diagonal check (Top-Left to Bottom-Right)
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
        // Anti-diagonal check (Top-Right to Bottom-Left)
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;

        return false; // No winning condition met
    }

    // Checks if the board is completely full (used to detect draws)
    bool isBoardFull() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                // If any spot is still an empty space, the board is not full
                if (board[i][j] == ' ') return false;
            }
        }
        return true; // Every single spot is taken
    }

    // Handles input and validation for a human player's move
    void playerMove(char player) {
        int row, col;
        while (true) {
            cout << "Player " << player << ", enter row and column (0-2): ";
            cin >> row >> col;

            // Check if user input is within grid boundaries and the chosen spot is empty
            if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
                board[row][col] = player; // Place the piece
                break;                    // Valid move done; exit the loop
            }
            else {
                cout << "Invalid move. Try again." << endl;
            }
        }
    }

    // Handles the AI opponent's turn by randomly generating a valid move
    void aiMove() {
        srand(time(0)); // Seed the random number generator using the current time
        int row, col;
        while (true) {
            // Generate a random number between 0 and 2 for both row and col
            row = rand() % SIZE;
            col = rand() % SIZE;

            // Ensure the randomly chosen spot isn't already occupied
            if (board[row][col] == ' ') {
                board[row][col] = 'O'; // AI always plays as 'O'
                break;                 // Valid move done; exit the loop
            }
        }
        cout << "AI chooses: " << row << " " << col << endl;
    }

    int main() {

        char choice; // Variable to store the user's choice for game mode

        do {
            int mode;
            cout << "Choose mode (1 for two-player, 2 for single-player): ";
            cin >> mode;

            // Game Setup
            initializeBoard();
            printBoard();
            char currentPlayer = 'X'; // Player 'X' always gets the first move

            if (mode == 1) {
                // Multi Player Mode (Two Human Players)
                while (true) {
                    playerMove(currentPlayer);
                    printBoard();

                    // Check if the move resulted in a win
                    if (isWinner(currentPlayer)) {
                        cout << "Player " << currentPlayer << " wins!" << endl;
                        break;
                    }
                    // Check if the move resulted in a draw
                    if (isBoardFull()) {
                        cout << "It's a draw!" << endl;
                        break;
                    }
                    // Toggle turn between 'X' and 'O' using a ternary operator
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            }
            else if (mode == 2) {
                // Single Player Mode (Vs AI) 
                while (true) {
                    // Human player is 'X', AI player is 'O'
                    if (currentPlayer == 'X') {
                        playerMove(currentPlayer);
                    }
                    else {
                        aiMove();
                    }
                    printBoard();

                    // Check win status
                    if (isWinner(currentPlayer)) {
                        if (currentPlayer == 'X') {
                            cout << "Player X wins!" << endl;
                        }
                        else {
                            cout << "AI wins!" << endl;
                        }
                        break;
                    }
                    // Check draw status
                    if (isBoardFull()) {
                        cout << "It's a draw!" << endl;
                        break;
                    }
                    // Pass the turn to the other player
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            }
            else {
                cout << "Invalid mode." << endl;
            }

            // Ask the user if they want to play again 
            cout << "\nWould you like to play again? (Y/N): ";
            cin >> choice;
            cout << endl;

        } while (choice == 'y' || choice == 'Y');

        cout << "Thanks for playing! Closing in 3 seconds..." << endl;


        this_thread::sleep_for(chrono::seconds(3)); // Freezes the program for exactly 3 seconds

        return 0;
    }

