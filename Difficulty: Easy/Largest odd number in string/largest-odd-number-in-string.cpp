//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string s) {
        // your code here
        int n= s.length();
        long long maxi = 0;
        string str= "" , r="";
        for(int i= 0; i< n; i++){
            str+=s[i];
            if((s[i]-'0')%2==1){r = str;
            }
        }
        return r;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends