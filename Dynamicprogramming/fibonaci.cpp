#include<iostream>
#include <vector>
using namespace std;

int fibo(int n){
    if(n==1 || n==2) return 1;
    vector<int> fibo = {0,1,1};

    for (int i=3; i<=n; i++){
        fibo.push_back(fibo[i-1]+fibo[i-2]);
    }
}

main(){
    int n;
    cout<<"nhap n: ";
    cin>>n;
    cout<<"fibonaci cua "<<n<<": "<<fibo(n);
}