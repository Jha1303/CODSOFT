#include <iostream>
#include <vector>

// Function to display the game board
void displayBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Checking rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // Checking columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    // Checking diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

// switch players
char switchPlayer(char player) {
    return (player == 'X') ? 'O' : 'X';
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;
    
    while (!gameWon && !gameDraw) {
        // Displaying the current state of the board
        displayBoard(board);
        
        //  enter move
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row column): ";
        std::cin >> row >> col;
        
        // Update the game board with the player's move
        board[row][col] = currentPlayer;
        
        // Check if the current player has won
        gameWon = checkWin(board, currentPlayer);
        
        // Check if the game is a draw
        gameDraw = checkDraw(board);
        
        
        currentPlayer = switchPlayer(currentPlayer);
    }
    
    // final state
    displayBoard(board);
    
    if (gameWon) {
        std::cout << "Player " << currentPlayer << " wins!" << std::endl;
    } else {
        std::cout << "The game is a draw." << std::endl;
    }
    
    return 0;
}


