 for (int i=3; i<=n; i++){
        fibo.push_back(fibo[i-1]+fibo[i-1]);
    }
    for(int i : fibo){
        cout<<i<<" ";
    }
    return fibo[n];