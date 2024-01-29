//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void fun(int idx , int n , string &S , vector<string> &vct , vector<vector<string>> &vtr){
      if(n==idx){
          vtr.push_back(vct);
          return;
      }
      for(int i = idx ; i<n ; i++){
          string str = S.substr(idx , i-idx+1);
          if(str == string(str.rbegin(),str.rend())){
              vct.push_back(str);
              fun(i+1,n,S,vct,vtr);
              vct.pop_back();
          }
      }
  }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        int n = S.size();
        vector<string>vct;
        vector<vector<string>>vtr;
        fun(0,n,S,vct,vtr);
        return vtr;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends