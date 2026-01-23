#include<bits/stdc++.h>
using namespace std;

void reverse(string &s, int idx){
    if (idx >= s.size()/2){
        return;
    }
    swap(s[idx], s[s.size()-1-idx]);
    reverse(s, idx+1);
}

int main(){
    string s = "venom";
    reverse(s, 0);
    cout << "reversed string: " << s << endl;
    return 0;
}