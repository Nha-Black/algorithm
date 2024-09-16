#include <iostream>
#include <vector>

using namespace std;

void generateBinary(int n, vector<int>& binaryVec, int index) {
    if (index == n) {
        for (int bit : binaryVec) {
            cout << bit;
        }
        cout << endl;
        return;
    }

    binaryVec[index] = 0;
    generateBinary(n, binaryVec, index + 1);

    binaryVec[index] = 1;
    generateBinary(n, binaryVec, index + 1);
}

int main() {
    int n;
    cin >> n;

    vector<int> binaryVec(n);

    generateBinary(n, binaryVec, 0);

    return 0;
}
