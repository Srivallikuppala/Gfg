//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> queue_sri;
        vector<int> visited(V+1,0);
        vector<int> vector_1;
        queue_sri.push(0);
        visited[0] = 1;
        while(!queue_sri.empty()){
            int x = queue_sri.front();
            queue_sri.pop();
            vector_1.push_back(x);
            for(auto it:adj[x]){
                if (visited[it]==0){
                    queue_sri.push(it);
                    visited[it] = 1;
                }
            }
        }
        return vector_1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends