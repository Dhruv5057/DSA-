#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool dfs(
    vector<vector<char>>& board,
    string& word,
    int row,
    int col,
    int index
) {
    // Entire word found
    if (index == word.length()) {
        return true;
    }

    // Out of bounds
    if (row < 0 || row >= board.size() ||
        col < 0 || col >= board[0].size()) {
        return false;
    }

    // Character doesn't match
    if (board[row][col] != word[index]) {
        return false;
    }

    // Mark cell as visited
    char temp = board[row][col];
    board[row][col] = '#';

    // Explore 4 directions
    bool found =
        dfs(board, word, row + 1, col, index + 1) ||
        dfs(board, word, row - 1, col, index + 1) ||
        dfs(board, word, row, col + 1, index + 1) ||
        dfs(board, word, row, col - 1, index + 1);

    // Backtrack
    board[row][col] = temp;

    return found;
}

bool exist(vector<vector<char>>& board, string word) {

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {

            if (board[i][j] == word[0]) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> board(rows, vector<char>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> board[i][j];
        }
    }

    string word;
    cin >> word;

    cout << (exist(board, word) ? "true" : "false") << endl;

    return 0;
}