#include <iostream>
#include <vector>
using namespace std;

main(){
    int n,k;
    cout<<"n k\n";
    cin>>n>>k;
    vector<vector<int>> data(n+1,vector<int>(k+1,0));
    for (int i=1; i<=n;i++){
        data[i][0]=1;
    }
    for(int i=1; i<=k; i++){
        data[i][i]=1;
    }
    for(int i=2;i<=n;i++){
        for (int j=1; j<=k; j++){
            if (j<=i){
                data[i][j]=data[i-1][j-1]+data[i-1][j];
            }
        }
    }
    cout<<data[n][k];
    //C(n,k)= C(n-1,k-1)+C(n-1,k);
    //C(n,n)=C(n,0)=1;
}