#include <iostream>
#include <vector>

using namespace std;

void init(int n, vector<int>& binaryVec, int index) {
    if (index == n) {
        for (int bit : binaryVec) {
            cout << bit;
        }
        cout << endl;
        return;
    }

    binaryVec[index] = 0;
    init(n, binaryVec, index + 1);

    binaryVec[index] = 1;
    init(n, binaryVec, index + 1);
}

int main() {
    int n;
    cin >> n;

    vector<int> binaryVec(n);

    init(n, binaryVec, 0);

    return 0;
}
