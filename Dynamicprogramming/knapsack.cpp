#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int knapSack(int W, int w[], int v[], int n) {
   int i, wt;
   int K[n + 1][W + 1];
   for (i = 0; i <= n; i++) {
      for (wt = 0; wt <= W; wt++) {
         if (i == 0 || wt == 0)
         K[i][wt] = 0;
         else if (w[i - 1] <= wt)
            K[i][wt] = max(v[i - 1] + K[i - 1][wt - w[i - 1]], K[i - 1][wt]);
         else
        K[i][wt] = K[i - 1][wt];
      }
   }
   // for(int i=1;i<=n;i++){
   //    for (int j=1;j<=W;j++) cout<<K[i][j]<<" ";
   //    cout<<"\n";
   // }
   //truy vết
   vector<int> items;
   int L=W;
  cout<<L<<"\n";
   for (int i=n;i>0;i--){
      if(K[i][L]!=K[i-1][L]){
         cout<<w[i-1]<<" ";
         
         L-=w[i-1];
         //cout<<w[i]<<" "<<L<<"\n";
      }
   }
   //for (int i:items) cout<<i<<"";
   
   return K[n][W];
}
int main() {
   cout << "Enter the number of items in a Knapsack:";
   int n, W;
   cin >> n>>W;
   int v[n], w[n];
   for (int i = 0; i < n; i++) {
      //cout << "Enter value and weight for item " << i << ":";
      cin >> w[i];
      cin >> v[i];
   }
   cout << knapSack(W, w, v, n);
   return 0;
}