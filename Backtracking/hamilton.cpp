#include<iostream>
#include<vector>
using namespace std;

vector<int> current;

void print(){
    for (int i : current){ 
        cout << i << " ";
    }
    cout << endl;
}

bool issafe(int check){
    for (int i : current){
        if (i == check) 
            return false;
    }
    return true;
}

bool hamilton(vector<vector<int>>& datas, int n, int v){
    if (current.size() == n){
        
        if (datas[v][current[0]] == 1){
            print();  
            return true;
        }
        return false;
    }

    
    for (int i = 1; i <=n; i++){
        if (datas[v][i] == 1 && issafe(i)){
            current.push_back(i);  
            if (hamilton(datas, n, i)){
                return true;
            }
            current.pop_back(); 
        }
    }
    return false;
}

int main()
{
    int n, m;  
    int x, y;
    
    cin >> n >> m; 
     
    vector<vector<int>> datas(n+1, vector<int>(n+1, 0));  
    
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        datas[x][y] = datas[y][x] = 1;  
    }

    current.push_back(1);  
    if (!hamilton(datas, n, 1)){
        cout << "Không tìm thấy đường đi Hamilton!\n";
    }
    return 0;
}
