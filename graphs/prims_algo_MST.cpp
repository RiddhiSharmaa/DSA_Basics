#include<bits/stdc++.h>
using namespace std;

int spanning_tree(int n, vector<pair<int,int>> adj[]){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int>vis(n,0);
    //{wt,node}
    pq.push({0,0});
    int sum=0;
    while (!pq.empty()){
        auto it=pq.top();
        int node=it.second;
        int wt=it.first;
        pq.pop();
        if (vis[node]==1) continue;
        vis[node]=1;
        sum=sum+wt;
        for (auto it: adj[node]){
            int adjNode=it.second;
            int adjWt=it.first;
            if (vis[adjNode]==0){
                pq.push({adjWt, adjNode});
            }
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