#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> next_smaller_element(int arr[], int n){
    vector<int>ans;
    stack<int>st;
    st.push(-1);
    for (int i = n-1; i >=0 ; i--){
        int curr = arr[i];
        while (st.top() >= curr){
            st.pop();
        }
        ans.push_back(st.top());
        st.push(curr);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> prev_smaller_element(int arr[], int n){
    vector<int>ans;
    stack<int>st;
    st.push(-1);
    for (int i = 0; i < n ; i++){
        int curr = arr[i];
        while (st.top() >= curr){
            st.pop();
        }
        ans.push_back(st.top());
        st.push(curr);
    }
    return ans;
}

int main(){
    int n = 5;
    int v[n] = {8,4,6,2,3};
    vector<int>ans = next_smaller_element(v, n);
    for (int i = 0 ; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    cout << endl;

    vector<int>ans2 = prev_smaller_element(v, n);
    for (int i = 0 ; i < ans.size(); i++){
        cout << ans2[i] << " ";
    }
    return 0;
}