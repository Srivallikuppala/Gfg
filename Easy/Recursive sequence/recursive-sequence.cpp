//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        long long r = 1 , k = 1 , c = 0;
        long long MOD = 1000000007;
        for(int i = 1 ; i < n+1 ; i++){
            r = 1;
            for(int j = 1 ; j<i+1 ; j++){
                r = ((r%MOD)*(k%MOD))%MOD;
                k+=1;
            }
        
            c = ((c%MOD)+(r%MOD))%MOD;
            //cout<<c<<" ";
        }
        return c%MOD;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends