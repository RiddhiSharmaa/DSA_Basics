#include<bits/stdc++.h>
using namespace std;

vector<int> shortest_path(int n, int m, vector<vector<int>> & edges){
    vector<pair<int,int>>adj[n+1]; //n+1 kyunki 1 based indexing hai
    for (auto it: edges){
        adj[it[0]].push_back({it[2],it[1]});
        adj[it[1]].push_back({it[2],it[0]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int>dist(n+1,1e9);
    //we made a parent vector jo ye batata hai ki koi number konse parent se aaya hai
    //for eg: 5 ka dist is 7 aur 5 kaha se aaya? 2 se toh 2 is the parent of 5
    //2 vo number hai jiski adjacency list se 5 ko liya gya and shortest dist mila hame
    vector<int>parent(n+1);
    for (int i=0; i<n+1; i++) parent[i]=i;
    dist[1]=0;
    pq.push({0,1});
    while (!pq.empty()){
        auto it= pq.top();
        int node= it.second;
        int dis=it.first;
        pq.pop();
        for (auto it: adj[node]){
            int adjNode=it.second;
            int adjWeight=it.first;
            if (dis + adjWeight<dist[adjNode]){
                dist[adjNode]=dis + adjWeight;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode]=node; //update the parent of that adjNode
            }
        }
    }
    if (dist[n]==1e9) return {-1};
    vector<int> path;
    int node=n;
    while (parent[node]!=node){//this condition because only the source is the parent of itself,so it will stop there
        path.push_back(node);
        node=parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n = 5, m = 6;
    vector<vector<int>> edges = {
        {1, 2, 2},
        {2, 5, 5},
        {2, 3, 4},
        {1, 4, 1},
        {4, 3, 3},
        {3, 5, 1}
    };

    vector<int> path = shortest_path(n, m, edges);

    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}