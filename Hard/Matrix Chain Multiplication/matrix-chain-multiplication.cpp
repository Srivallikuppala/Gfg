//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[101][101];
    int fun(int i , int j , int arr[]){
        if(i>=j )return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = 1e9;
        for(int k = i ; k < j; k++){
            int r = fun(i,k,arr);
            int l = fun(k+1,j,arr);
            //cout<<r<<" "<<l<<" "<<arr[k]<<" "<<arr[j]<<endl;
            mini = min(mini,r+l+(arr[i-1]*arr[k]*arr[j]));
            //cout<<mini<<endl;
        }
        dp[i][j] = mini;
        return mini;
    }
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return fun(1,n-1,arr);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends