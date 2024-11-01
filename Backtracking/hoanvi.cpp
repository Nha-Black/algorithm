#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& perm) {
    for (int num : perm) {
        cout << num << " ";
    }
    cout << endl;
}

void generatePermutations(vector<int>& perm, vector<bool>& used, int n) {
    if (perm.size() == n) {
        print(perm);
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            used[i] = true;
            perm.push_back(i); 

            generatePermutations(perm, used, n);

            perm.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    
    vector<int> perm; 
    vector<bool> used(n + 1, false); 
    cout << "Cac hoan vi cua cac so tu 1 den " << n << " la:" << endl;
    generatePermutations(perm, used, n);

    return 0;
}
