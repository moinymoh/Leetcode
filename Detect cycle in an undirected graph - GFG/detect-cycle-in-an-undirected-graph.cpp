//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool bfs(int src, vector<int> adj[], vector<int>& vis) {
        bool ans = false;

        queue<pair<int, int>> q;
        

        q.push(make_pair(src, -1));
        vis[src] = 1;

        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto adjacentNode : adj[node]) {
                
                if(vis[adjacentNode] == 0) {
                    q.push(make_pair(adjacentNode, node));
                    vis[adjacentNode] = 1;
                } else if(parent != adjacentNode) {
                    return true;
                }
            }
        }

        return ans;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool ans = false;
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++) {
            if(vis[i] == 0)
                ans = ans || bfs(i, adj, vis);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends