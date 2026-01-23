#include<bits/stdc++.h>
using namespace std;

void find_subsequences(string s, int idx, int len, string output){
    if (idx == len){
        cout << "-> " << output << endl;
        return;
    }
    //exclude char ch
    find_subsequences(s, idx+1, len, output);
    //include char ch
    output += s[idx];
    find_subsequences(s, idx+1, len, output);
}

int main(){
    string s = "xyz";
    int len = s.length();
    string output = "";
    find_subsequences(s, 0, len, output);
    return 0;
}