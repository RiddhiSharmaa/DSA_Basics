#include <bits/stdc++.h>
using namespace std;

// int main() {
//     vector<int> v;
//     v.push_back(4);
//     v.emplace_back(9);
//     for (int i : v) {
//         cout << i << " ";
//     }
//     cout << endl;
//     cout<<v[1];
//     return 0;
// }


int main() {
    vector<int>v;
    v.push_back(4);
    v.push_back(6);
    v.push_back(7);
    v.push_back(2);
    v.push_back(3);
    vector<int>::iterator it=v.begin();
    cout<<*it<<" ";
    it=it+2;
    cout<<*it;
    vector<int>::iterator it1=v.end();
    cout<<*it1<<" ";
    return 0;
}











