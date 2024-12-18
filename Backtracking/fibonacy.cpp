#include<iostream>
using namespace std;

int fibo(int n){
    if(n==1 || n==2) return 1;
    return fibo(n-1) + fibo(n-2);
}

main(){
    int n;
    cout<<"nhap n: ";
    cin>>n;
    cout<<"fibonaci cua "<<n<<": "<<fibo(n);
}