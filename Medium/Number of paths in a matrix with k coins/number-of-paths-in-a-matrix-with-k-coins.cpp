//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long dp[101][101][101];
    long long fun(int i , int j , int k , int n , vector<vector<int>>&arr){
        
        if(i==n-1 and j==n-1){
            if(k==arr[i][j]){
                return 1;
            }
            return 0;
        }
        if( i>=n or j>=n or k<0){
            return 0;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
       // cout<<i<<" "<<j<<" "<<k<<endl
        long long a=fun(i+1,j,k-arr[i][j],n,arr);
        a+=fun(i,j+1,k-arr[i][j],n,arr);
        return dp[i][j][k] = a;
    }
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        
        // Code Heren or
        memset(dp,-1,sizeof(dp));
        return fun(0,0,k,n,arr);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends