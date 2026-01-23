#include<bits/stdc++.h>
using namespace std;

int find_RtoL(string &s, int idx, char &target){
    if (idx<0){
        return -1;
    }
    if (s[idx] == target){
        return idx;
    }
    return find_RtoL(s, idx-1, target);
}

int find_LtoR(string &s, int idx, char &target, int &ans){
    if (idx >= s.size()){
        return ans;
    }
    if (s[idx] == target){
        ans = idx;
    }
    return find_LtoR(s, idx+1, target, ans);
}

int find_STL(string &s, char &target){
    const char* cstr = s.c_str();
    const char* ptr = strrchr(cstr, target);
    if (ptr == nullptr){
        return -1;
    }
    return ptr-cstr;
}

int main(){
    string s = "finesse";
    char ch = 'e';
    int ans = -1;
    cout << find_RtoL(s, s.size()-1, ch) << endl;
    cout << find_LtoR(s, 0, ch, ans) << endl;
    cout << find_STL(s, ch) << endl;
    return 0;
}