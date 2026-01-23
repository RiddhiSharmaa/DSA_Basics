#include<bits/stdc++.h>
using namespace std;

void wavePrint(vector<vector<int>>mat){
    int row = mat.size();
    int col = mat[0].size();
    bool flag = true;
    for (int i = 0; i<col; i++){
        if (flag){
            for (int j = 0; j<row; j++){
                cout << mat[j][i] << " ";
            }
        }
        else{
            for (int j = row-1; j>=0; j--){
                cout << mat[j][i] << " ";
            }
        }
        flag = !flag;
    }
}

int main(){
    vector<vector<int>>mat{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
    };
    wavePrint(mat);
    return 0;
}