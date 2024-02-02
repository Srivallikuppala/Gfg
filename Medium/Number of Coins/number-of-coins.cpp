//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long long d[1000001];
	long long fun(vector<int>c,int cnt ,int res){
	    if(d[res]!=-1) return d[res];
	    if(res==0) return 0;
	    long long ans = INT_MAX;
	    for(int i = 0 ; i < cnt ; i++){
	        //cout<<ans<<" ";
	        if(res>=c[i])ans = min(ans,fun(c,cnt,res-c[i])+1);
	        //cout<<ans<<" ";
	    }
	    d[res]=ans;
	   // ans = min(ans,fun(c,cnt,res-c[idx],idx))+1;
	   // ans = min(ans,fun(c,cnt,res,idx+1))+1;
	   // cout<<ans<<" "<<idx<<" ";
	    return ans;
	}
	int minCoins(vector<int> &coins, int cnt, int res) 
	{ 
	    // Your code goes here
	    memset(d,-1,sizeof(d));
	    if(*min_element(coins.begin(),coins.end())>res) return -1;
	    long long x = fun(coins,cnt,res);
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