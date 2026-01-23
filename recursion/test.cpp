#include<bits/stdc++.h>
using namespace std;

bool palindrome(string s, int len, int idx){
    if (idx >= len/2){
        return true;
    }
    if (s[idx] != s[len-idx-1]){
        return false;
    }
    return palindrome(s, len, idx+1);
}

int main(){
    string s = "121";
    int len = s.length();
    int k = palindrome(s, len, 0);
    if (k == 1){
        cout << "True";
    }
    else{
        cout<< false;
    }
}