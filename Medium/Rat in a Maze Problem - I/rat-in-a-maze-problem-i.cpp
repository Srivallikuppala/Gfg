//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void path(int i , int  j , int a , string r , vector<string>&arr , vector<vector<int>>m , vector<vector<int>>&visit){
        if(i>a or j>a or i<0 or j<0 or visit[i][j]!=-1 or m[i][j]==0) return;
        if(i==a and j==a){
            arr.push_back(r);
            return;
        }
        visit[i][j]=1;
        path(i+1,j,a,r+'D',arr,m,visit);
        path(i,j+1,a,r+'R',arr,m,visit);
        path(i-1,j,a,r+'U',arr,m,visit);
        path(i,j-1,a,r+'L',arr,m,visit);
        visit[i][j]=-1;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]!=1 or m[n-1][n-1]!=1) return {};
        vector<string>arr;
        vector<vector<int>>visit(n,vector<int>(n,-1));
        path(0,0,n-1,"",arr,m,visit);
        return arr;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends