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
        long long mod = 1e9+7;
        long long a = (n*(n+1))/2;
        long long r = 1 , x = n , t=0;
        while(a){
            int y = x;
            r = 1;
            while(x){
                r = ((r%mod)*(a%mod))%mod;
            
                a-=1;
                x-=1;
            }
            x = y-1;
            //cout<<r<<" ";
            t=(t+r)%mod;
        }
        return t%mod;
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