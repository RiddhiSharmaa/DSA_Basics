#include<bits/stdc++.h>
using namespace std;

bool mycomp(int &a, int &b){
    return a>b;
}

bool mycomp2(vector<int> &a, vector<int> &b){
    return a[1]>b[1];
}

int main(){
    vector<int>arr = {2,5,3,6,3,4};
    sort(arr.begin(), arr.end(), mycomp);
    for (int i = 0; i<arr.size(); i++){
        cout<< arr[i] <<" ";
    }

    cout << endl;

    vector<vector<int>> arr2 = {{1,2}, {1,5}, {1,4}, {0,3}};
    sort(arr2.begin(), arr2.end(), mycomp2);
    for (int i = 0; i<arr2.size(); i++){
        for (int j = 0; j<arr2[i].size(); j++){
            cout<< arr2[i][j] <<" ";
        }
        cout << endl;
    }
    return 0;
}