#include <bits/stdc++.h>
using namespace std;

vector<int>dijkstra(int N, vector<vector<int>> &edges, int &src){
    vector<pair<int,int>>adj[N+1]; //n+1 kyunki 1 based indexing hai
    for (auto it: edges){
        adj[it[0]].push_back({it[2],it[1]});
        adj[it[1]].push_back({it[2],it[0]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int>dist(N,1e9);
    dist[src]=0;
    pq.push({0,src});
    while (!pq.empty()){ //o(N)
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();//o(log N)
        for (auto edge: adj[node]){ //o(E)
            int adjNode= edge.second;
            int edgeW= edge.first;
            if (dis+edgeW<dist[adjNode]){
                dist[adjNode]=dis+edgeW;
                pq.push({dist[adjNode], adjNode}); //log(N)
            }
        }
    }
    return dist;
}

int main(){
    int N=3; 
    int src=0;
    
    vector<vector<int>> edges = {
        {0, 1, 1}, //{u,v,weight}
        {0, 2, 6},
        {1, 0, 1},
        {1, 2, 3},
        {2, 1, 3},
        {2, 0, 6}
    };

    vector<int> res = dijkstra(N, edges, src);
    vector<char> characters={'A','B','C'};

    for (int i = 0; i < N; i++){
        cout << "distance from node " << characters[i]<< " is "<< res[i] << endl;
    }
    cout << endl;
    return 0;
}