#include <bits/stdc++.h>
using namespace std;

// basically aise order krdo ki if there is an edge from u->v u should be before v
// aise bhut orderings ho skti hai hame bas ek nikalni hai
// jisme saare directed edges issi way mei ho ki u v se pehle hai 
// it can be uvhisyfk or ubhfkfosv(example)

void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]) {
	vis[node] = 1;
	for (auto it : adj[node]) {
        //adj list ke har node ki list ke elements ko iterate kro
        //if not visited uske neighbours ko visit kro
        //finally when no visitors left, return and push the node in stack
		if (!vis[it]) dfs(it, vis, st, adj);
	}
	st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) {
	int vis[V] = {0};
	stack<int> st;

	for (int i = 0; i < V; i++) {
        //agar koi component connected nhi hai, toh visit them
		if (!vis[i]) {
			dfs(i, vis, st, adj);
		}
	}

	vector<int> ans;
	while (!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}
	return ans;
}

int main() {
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	vector<int> ans = topoSort(V, adj);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}

//O(V) for visiting each node once.
//O(E) for checking each edge once.
//total time: O(V + E)

//Space Complexity: O(2N) + O(N) ~ O(2N): O(2N) for the visited array and the stack 
//carried during DFS calls and O(N) for recursive stack space, where N = no. of nodes.