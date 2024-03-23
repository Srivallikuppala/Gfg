//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long mod = 1e9+7;
    void fun(vector<int> &v,int a,int n,int c){
        if (c==n) return;
        v.push_back((v[a-1]+v[a])%mod);
        fun(v,a+1,n,c+1);
        return;
    }
    vector<int> Series(int n) {
        // Code here
        vector<int>v;
        int a = 0 ,b = 1,c=1;
        v.push_back(a%mod);
        v.push_back(b%mod);
        fun(v,1,n,c);
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends