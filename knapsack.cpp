#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int knapsack(int W, vector<int> weights, int n) {
    if (n == 0 || W == 0)
        return 0;

    if (weights[n-1] > W)
        return knapsack(W, weights, n-1);

    else
        return max(
            knapsack(W, weights, n-1), 
            weights[n-1] + knapsack(W - weights[n-1], weights, n-1) 
        );
}

int main() {                     
    int n, m, W;
    cin >> n >> W;

    vector<int> weights(n);  

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Max weight : " << knapsack(W, weights, n) << endl;

    return 0;
}
