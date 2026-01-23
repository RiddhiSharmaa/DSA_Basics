#include<bits/stdc++.h>
using namespace std;

vector<int>bfs_of_Graph(int v, vector<int>adj[]){
    int vis[v]={0};
    vis[0]=1;
    queue<int>q;
    q.push(0);
    vector<int>bfs;
    while(!q.empty()){
        int node= q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it: adj[node]){
            if (vis[it]==0){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}

void dfs(int node, vector<int>adj[], int vis[], vector<int>&ls){
    vis[node]=1;
    ls.push_back(node);
    for (auto it:adj[node]){
        if (vis[it]==0){
            vis[it]=1;
            dfs(it, adj, vis, ls);
        }
    }
}

vector<int>dfs_of_Graph(int v, vector<int>adj[]){
    int vis[v]={0};
    int start=0;
    vector<int>ls;
    dfs(start, adj, vis, ls);
    return ls;
}

void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int>&ls){
    for (int i=0; i<ls.size(); i++){
        cout<<ls[i]<<" ";
    }
}

int main(){
    vector <int> adj[5];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    vector<int>ans=dfs_of_Graph(5, adj);
    printAns(ans);
}