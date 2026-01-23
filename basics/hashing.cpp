// #include<bits/stdc++.h>
// using namespace std;

// //number hashing
// // int main(){
// //     int n=5;
// //     int arr[n]={1,3,2,1,3};
// //     for (int i=0; i<n; i++){
// //         cout<<arr[i]<<" ";
// //     } 
// //     cout<< endl;

// //     //precompute
// //     int hash[13]={0};
// //     for (int i=0; i<n; i++){
// //         hash[arr[i]]+=1;
// //     }

// //     int num;
// //     cout<<"enter: ";
// //     cin>>num;
// //     //fetch
// //     cout<<hash[num];
// //     return 0;    
// // }



// //character hashing
// // int main(){
// //     string s="abcdeohabcdancbd";

// //     //precompute
// //     int hash[26]={0};
// //     for (int i=0; i<=s.size(); i++){
// //         hash[s[i]-'a']+=1;
// //     }

// //     //fetch
// //     char k;
// //     cout<<"enter: ";
// //     cin>>k;
// //     cout<<"it occurs "<< hash[k-'a']<<" times.";

// //     return 0;
// // }



// //character hashing
// // int main(){
// //     string s="aabcadAHOGTAHOMHYSKAasancbd";

// //     //precompute
// //     int hash[256]={0};
// //     for (int i=0; i<=s.size(); i++){
// //         hash[s[i]]+=1;
// //     }

// //     //fetch
// //     char k;
// //     cout<<"enter: ";
// //     cin>>k;
// //     cout<<"it occurs "<< hash[k]<<" times.";

// //     return 0;
// // }



// //mapping
// // int main(){
// //     int n=14;
// //     long arr[n]={2,3,1,3,4,6,4,2,3,5,1,9,7,6};
// //     map<int,int>mpp;
// //     for (int i=0; i<n; i++){
// //         mpp[arr[i]]+=1;
// //     }

// //     int num;
// //     cout<<"enter: ";
// //     cin>>num;
// //     //fetch
// //     cout<<mpp[num];
// //     return 0;
// // }




// //mapping
// // int main(){
// //     string s="abfbgbedfACJBSBUSKAHDABJ";
// //     map<char,int>mpp;
// //     for (int i=0; i<s.size(); i++){
// //         mpp[s[i]]+=1;
// //     }

// //     char ch;
// //     cout<<"enter: ";
// //     cin>>ch;
// //     //fetch
// //     cout<<mpp[ch];
// //     return 0;
// // }


// int main(){
//     int n=5;
//     int arr[n]={2,3,2,3,5};
//     for (int i=0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<< endl;

//     //precompute
//     int hash[5]={0};
//     for (int i=0; i<n; i++){
//         hash[arr[i]-1]+=1;
//     }

//     for (int i=0; i<n; i++){
//         cout<<hash[i]<<" ";}
        
//     return 0;
// }

// //{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;


// // } Driver Code Ends
// class Solution {
//   public:
//     // Function to count the frequency of all elements from 1 to N in the array.
//     void frequencyCount(vector<int>& arr,int N, int P){
//         int N=arr.size();
//         int arr[N];
        
//         vector<int>hash(N,0);
    
//         //precompute
//         for (int i=0; i<N; i++){
//             hash[arr[i]-1]+=1;
//         }
            
//         return hash;
//     }
// };


// //{ Driver Code Starts.

// int main() {
//     int t; // Number of test cases
//     cin >> t;
//     cin.ignore(); // Ignore the newline after the integer input
//     while (t--) {
//         vector<int> a;
//         string input;

//         // Input format: first number n followed by the array elements
//         getline(cin, input);
//         stringstream ss(input);
//         int num;
//         while (ss >> num)
//             a.push_back(num); // Read the array elements from input string

//         Solution obj;
//         vector<int> result = obj.frequencyCount(a);

//         // Print the result in the required format
//         if (result.empty()) {
//             cout << "[]"; // Print empty brackets if no duplicates are found
//         } else {
//             for (int i = 0; i < result.size(); i++) {
//                 if (i != 0)
//                     cout << " ";
//                 cout << result[i];
//             }
//         }
//         cout << endl; // Ensure new line after each test case output
//     }

//     return 0;
// }

// // } Driver Code Ends





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
            if (i<adjNode){
                edges.push_back({wt,{node,adjNode}});}
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