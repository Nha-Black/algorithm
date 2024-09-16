#include <iostream>
#include <vector>

using namespace std;


bool isSafe(const vector<vector<int>>& board, int row, int col, int N) {
    // Kiểm tra cột
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Kiểm tra đường chéo trên
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Kiểm tra đường chéo dưới
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row, int N) {
    if (row >= N) {
        return true;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;

            if (solveNQueens(board, row + 1, N)) {
                return true;
            }

            board[row][col] = 0;
        }
    }

    return false;
}

void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << (cell ? "Q " : ". ");
        }
        cout << endl;
    }
}

int main() {
    int N;
    cout << "Nhập kích thước bàn cờ N (N x N): ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueens(board, 0, N)) {
        cout << "Một cách đặt quân hậu là:" << endl;
        printBoard(board);
    } else {
        cout << "Không có cách đặt quân hậu hợp lệ." << endl;
    }

    return 0;
}
