//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long long dp[99][10002];
	long long fun(vector<int>c,int cnt ,int res , int idx ){
	    if(idx >= cnt){
	        if(res == 0) return 0;
	        return INT_MAX;
	    }
	    if(dp[idx][res]!=-1){
	        return dp[idx][res];
	    }
	    long long ans = INT_MAX;
	    ans = min(ans,fun(c,cnt,res,idx+1));
	    if(res>=c[idx]) ans = min(ans,1+fun(c,cnt,res-c[idx],idx));
	    dp[idx][res] = ans;
	    return ans;
	}
	int minCoins(vector<int> &coins, int cnt, int res) 
	{ 
	   //vector<vector<long long>>d(cnt,vector<long long>(res,-1));
	   memset(dp,-1,sizeof(dp)) ;
	    long long x = fun(coins,cnt,res,0);
	   
	    if(x==INT_MAX) return -1;
	    return x;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends