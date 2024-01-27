//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> call(vector<int>&vct , int x , int n , int m , int i){
        vct[i] = (m);
        if(n==m){
            return vct;
        }
        if(m<=0){
            x = 5;
        }
        call(vct , x , n , m+x , i+1);
        return vct;
    }
    vector<int> pattern(int n){
        // code here
        int a;
        if(n<=0){
            vector<int>vect(1);
            vect[0]=n;
            return vect;
        }
        if(n%5==0) a = ((n/5)*2)+1;
        else a = (((n/5)+1)*2)+1;
        vector<int>vct(a);
        vct[0] = n;
        call(vct , -5 , n , n-5 , 1);
        return vct;
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
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends