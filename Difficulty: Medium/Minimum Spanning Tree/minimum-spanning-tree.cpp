//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int>rank,parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    
    int findUltimateParent(int node){
        if(node==parent[node])return node;
        return parent[node]=findUltimateParent(parent[node]);
    }
    
    void unionByRank(int node1,int node2){
        int parent1=findUltimateParent(node1);
        int parent2=findUltimateParent(node2);
        
        if(parent1==parent2)return;
        else if(rank[parent1]<rank[parent2]){
            parent[parent1]=parent2;
        }
        else if(rank[parent2]<rank[parent1]){
            parent[parent2]=parent1;
        }
        else if(rank[parent1]==rank[parent2]){
            parent[parent2]=parent1;
            rank[parent1]++;
        }
    }
    
};
 
class Solution
{
public:
//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       vector<pair<int,pair<int,int>>>edges;
       
      for(int i=0;i<V;i++){
       for(auto j:adj[i]){
           int adjNode=j[0];
           int adjWeight=j[1];
           int currentNode=i;
           
           edges.push_back({adjWeight,{currentNode,adjNode}});
       }
      }
       
       sort(edges.begin(),edges.end());
       int ans=0;
       DisjointSet d(V);
       
       for(auto &i:edges){
           int weight=i.first;
           int node1=i.second.first;
           int node2=i.second.second;
           
           if(d.findUltimateParent(node1)!=d.findUltimateParent(node2)){
               ans+=weight;
               d.unionByRank(node1,node2);
           }
       }
       return ans;
    }
};
// class Solution
// {
//     vector<int> rank;
//     vector<int> parent;
//     public:
//     void disjoint_set(int V){
//         rank.resize(V+1,0);
// 	    parent.resize(V+1,0);
// 	    for(int i= 0; i<= V; i++) parent[i]= i;
//     }
//     int find_root(int n){
// 	    if(parent[n]==n) return n;
// 	    return parent[n]= find_root(parent[n]);
// 	}
//     void union_find(int a, int b){
// 	    int x= find_root(a);
// 	    int y= find_root(b);
// 	    if(rank[x]==rank[y]){
// 	        parent[x]= y;
// 	        rank[y]++;
// 	    }
// 	    else if(rank[x]>rank[y]){
// 	        parent[y]= x;
// 	    }
// 	    else{
// 	        parent[x]= y;
// 	    }
	    
// 	}
//     int spanningTree(int V, vector<vector<int>> adj[])
//     {
//         // code here
//         disjoint_set(V);
//         vector<pair<int,pair<int,int>>> edges;
//         // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> edges;
//         for (int i = 0; i < V; i++) {
//             for (auto it : adj[i]) {
//                 edges.push_back({it[1], {it[0], i}});
//             }
//         }
//         int sum= 0;
//         sort(edges.begin(),edges.end());
//         for(auto it: edges){
//             // auto it= edges.top();
//             // edges.pop();
//             if(find_root(it.second.second)!=find_root(it.second.first)){
//                 sum+=it.first;
//                 union_find(it.second.second,it.second.first);
//             }
//         }
//         return sum;
        
//     }
// };


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends