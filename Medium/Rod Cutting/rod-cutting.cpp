//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int dp[n+1] = {0};
        for(int len = 1 ; len<=n ; len++){
            int ma = INT_MIN;
            for(int i = 0 ; i < len ; i++){
                int sub = price[i]+dp[len-i-1];
                ma = max(ma,sub);
            }
            dp[len] = ma;
            //cout<<ma<<" ";
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends