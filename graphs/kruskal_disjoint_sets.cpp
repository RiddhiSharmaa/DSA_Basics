#include <bits/stdc++.h>
using namespace std;

vector<int>parent, rank_, size;

void Disjoint_set(int n){
    parent.resize(n+1);
    rank_.resize(n+1,0);
    size.resize(n+1, 1);
    for (int i=0; i<n+1; i++) parent[i]=i;
}

int find_ultimate_parent(int node){
    if (parent[node]==node) {
        return node;}
    return parent[node]=find_ultimate_parent(parent[node]); //path compression
}

void UnionByRank(int u, int v){
    int ulp_u=find_ultimate_parent(u);
    int ulp_v=find_ultimate_parent(v);
    if (ulp_u==ulp_v) return;
    if (rank_[ulp_u]>rank_[ulp_v]){
        parent[ulp_v]=ulp_u;
    }
    else if (rank_[ulp_u]<rank_[ulp_v]){
        parent[ulp_u]=ulp_v;
    }
    else{
        parent[ulp_u]=ulp_v;
        rank_[ulp_v]++;
    }
}

void UnionBySize(int u, int v){
    int ulp_u=find_ultimate_parent(u);
    int ulp_v=find_ultimate_parent(v);
    if (ulp_u==ulp_v) return;
    if (size[ulp_u]>size[ulp_v]){
        parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
    else{
        parent[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
    }
}

int spanning_tree(int V, vector<pair<int,int>>adj[]){
    vector<pair<int,pair<int,int>>>edges;
    int node=0;
    for (int i=0; i<V; i++){
        for (auto it: adj[i]){
            int adjNode=it.first;
            int wt=it.second;
            int node=i;
            edges.push_back({wt,{node,adjNode}});
        }
    }

    sort(edges.begin(), edges.end());

    Disjoint_set(V);
    int mst_weight=0;
    vector<pair<int,int>>mst_edges;

    for (auto it: edges){
        int wt=it.first;
        int u= it.second.first;
        int v=it.second.second;
        if (find_ultimate_parent(u)!=find_ultimate_parent(v)){
            mst_weight+=wt;
            UnionByRank(u,v);
            mst_edges.push_back({u,v});
        }
    }
    for (auto it: mst_edges){
        cout<<it.first<<"--"<<it.second<<endl;
    }
    return mst_weight;
}

int main(){
    int n=5;
    vector<vector<int>>edges={
        {0, 1, 2}, {0, 2, 1}, {1, 2, 1},
        {2, 3, 2}, {3, 4, 1}, {4, 2, 2}
    };
    vector<pair<int,int>>adj[n];
    for (auto it: edges){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    int mst_weight = spanning_tree(n, adj);
    cout << "The sum of all the edge weights in the MST: " << mst_weight << endl;
    return 0;
}