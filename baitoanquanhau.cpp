#include <iostream>
#include <vector>
using namespace std;

int N; 

bool isSafe(vector<vector<int>>& board, int row, int col) {
    
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Kiểm tra đường chéo trên bên trái
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Kiểm tra đường chéo trên bên phải
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int row) {
    // Nếu đã đặt đủ N quân hậu thì return true
    if (row >= N)
        return true;

    // Duyệt qua các cột để thử đặt quân hậu
    for (int col = 0; col < N; col++) {
        // Nếu có thể đặt quân hậu tại (row, col)
        if (isSafe(board, row, col)) {
            // Đặt quân hậu tại vị trí (row, col)
            board[row][col] = 1;

            // Đệ quy kiểm tra đặt quân hậu tiếp theo
            if (solveNQueensUtil(board, row + 1))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

// Hàm giải bài toán N quân hậu
bool solveNQueens() {
    // Khởi tạo bàn cờ N x N với các vị trí đều bằng 0
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueensUtil(board, 0)) {
        cout << "Không tìm thấy lời giải\n";
        return false;
    }

    // In ra bàn cờ với các quân hậu đã đặt
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "1 " : "0 ");
        cout << endl;
    }

    return true;
}

int main() {
    cin>>N;
    solveNQueens();
    return 0;
}
