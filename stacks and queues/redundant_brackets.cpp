#include <iostream>
#include <stack>
using namespace std;

bool checkRedundant(string str){
    stack<char>st;
    for (int i = 0; i < str.size(); i++){
        char ch = str[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else if( ch == ')'){
            int opcnt = 0;
            while (!st.empty() && st.top() != '('){
                char temp = st.top();
                if ( temp == '+' || temp == '*' || temp == '-' || temp == '/'){
                    opcnt++;
                }
                st.pop();
            }
            st.pop();

            if (opcnt == 0){
                return true;
            }
        }
    }

    return false;
}

int main(){
    string str = "((a+b)*(c+d)))";
    bool ans = checkRedundant(str);
    cout << ans;

}