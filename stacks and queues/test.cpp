#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;


int main() {
    string s;
    getline(cin, s);
    stack<char>st;
    int len = s.length();
    for (int i = len-1; i >= 0; i--){
        if ((s[i] == '*' || s[i] == '$' || s[i] == '#' ) && !st.empty()){
            st.pop();
        } else if ((s[i] >= 'a') && (s[i] <= 'z' )){
            st.push(s[i]);
        } else if (s[i] == ' '){
            st.push('*');
        }
    }

    string ans = "";
    while (!st.empty()){
        char c = st.top();
        if (c == '*'){
            ans += ' ';
        } else{
            ans += c;
        }
        st.pop();
    }
    cout << ans;
    return 0;
}