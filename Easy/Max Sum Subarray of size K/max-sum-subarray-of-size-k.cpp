//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        long long maxi = 0;
        for(long long i = 0 ; i < k ; i++){
            maxi+=arr[i];
        }
        long long s = maxi;
        long long j=0;
        for(long long i = k ; i < n  ; i++){
            s-=arr[j];
            s+=arr[i];
            j+=1;
            
            maxi = max(maxi,s);
        }        
        return maxi;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends