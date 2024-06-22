//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        // code here
        int n= sentence.size(), t= 1;
        long long int1 = 0, maxi= 0;
        for(int i= 0; i< n; i++){
            if(sentence[i]>='0' and sentence[i]<='9'){
                if(sentence[i]=='9') t= 0;
                int1 = (int1*10)+(sentence[i]-'0');
            }
            else{
                if(t==1)maxi = max(maxi,int1);
                t= 1;
                int1= 0;
            }
        }
        if(t==1)maxi = max(maxi,int1);
        // cout<<maxi;
        if(maxi==0) return -1;
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends