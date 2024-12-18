#include <iostream>
#include <vector>
using namespace std;
vector<int> datas;
void print(vector<int> vector){
    for(int i=0; i<vector.size(); i++){
        cout<<vector[i]<<" ";
    }
    cout<<"\n";
}

void tohop(int start, int r, int n, vector<int>& current){
    if(current.size()==r){
        print(current);
        return;
    }
    for(int i=start; i<=n;i++){
        current.push_back(datas[i-1]);
        tohop(i+1,r,n,current);
        current.pop_back();
    }
}

int main(){
    int r,n,m;
    cin>>r>>n;
    for(int i=0; i<n;i++){
        cin>>m;
        datas.push_back(m);
    }
    vector<int> current;
    tohop(1,r,n,current);

    return 0;

}