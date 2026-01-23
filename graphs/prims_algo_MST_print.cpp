#include<bits/stdc++.h>
using namespace std;

int spanning_tree(int n, vector<pair<int,int>> adj[]){
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<int>vis(n,0);
    vector<pair<int,int>>mst_edges;
    //{wt,node}
    pq.push({0,0,-1});
    int sum=0;
    while (!pq.empty()){
        auto [wt,node,parent]=pq.top();
        pq.pop();
        if (vis[node]==1) continue;
        vis[node]=1;
        sum=sum+wt;
        if (parent!=-1){
            mst_edges.push_back({parent,node});
        }
        for (auto it: adj[node]){
            int adjNode=it.second;
            int adjWt=it.first;
            if (vis[adjNode]==0){
                pq.push({adjWt, adjNode});
            }
        }
        for (auto [u, v] : mstEdges) {
            cout << u << " -- " << v << endl;
        }
    }
    return sum;
}

int main() {

	int n = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	vector<pair<int, int>> adj[n];
    for (auto it : edges) {
        int u = it[0], 
        v = it[1], 
        wt = it[2];
        adj[u].push_back({wt,v});
        adj[v].push_back({wt,u});
    }

	int sum = spanning_tree(n, adj);
	cout << "The sum of all the edge weights: " << sum << endl;

	return 0;
}