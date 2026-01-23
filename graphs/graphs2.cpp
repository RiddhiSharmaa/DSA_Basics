#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int N, int M, vector<vector<int>>& edges, int src) {
    vector<int> adj[N];
    for (auto it : edges) { //o(E)
        //edges ko iterate kr rha hai
        //it[0] is {0,1} mei se 0 and it[1] is 1 
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    //distance array banakr saare dist inf krdiye aur source ka dist 0
    int dist[N]; //o(N)
    for (int i = 0; i < N; i++) dist[i] = 1e9;

    dist[src] = 0;
    //queue banakr pushed src
    queue<int> q;
    q.push(src);

    while (!q.empty()) { //o(N)
        int node = q.front();
        q.pop();
        for (auto it : adj[node]) { //o(2E)
            //adj list ke har ek vector list ko pick kiya like eg 0 then uske neighbours ko auto it ne iterate kiya
            if (dist[node] + 1 < dist[it]) {
                //agar dist of node +1 is less than dist of it then update
                // eg dist[0]+1= 0+1= 1 <dist[3] jaha dist[3] abhi inf hai, toh update 3 ka dist
                dist[it] = dist[node] + 1;
                //update krte hi push into queue
                q.push(it);
            }
        }
    }

    vector<int> ans(N, -1);
    for (int i = 0; i < N; i++) { //o(N)
        if (dist[i] != 1e9) ans[i] = dist[i];
    }

    return ans;
}

int main() {
    int N = 9, M = 10;
    vector<vector<int>> edges = {
        {0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6},
        {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}
    };

    vector<int> ans = shortestPath(N, M, edges, 0);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
