#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Hàm tìm LCS giữa hai chuỗi X và Y
string findLCS(const string &X, const string &Y) {
    int m = X.length();
    int n = Y.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Điền giá trị cho bảng dp
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Truy ngược bảng dp để tìm LCS
    int i = m, j = n;
    string lcs = "";
    while (i > 0 && j > 0) {
        // Nếu ký tự tương ứng khớp nhau, thêm vào LCS
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        } 
        // Di chuyển theo hướng có giá trị lớn hơn
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    for (int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }

    return lcs;
}

int main() {
    string X, Y;
    cout << "Nhap chuoi X: ";
    cin >> X;
    cout << "Nhap chuoi Y: ";
    cin >> Y;

    string lcs = findLCS(X, Y);
    cout << "Do dai LCS: " << lcs.length() << endl;
    cout << "LCS: " << lcs << endl;

    return 0;
}
