//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<long long,int>>que;
        int mini = INT_MAX;
        //if(start>end)return -1;
        if(start==end) return 0;
        que.push({start,0});
        vector<int>visited(100000,0);
        long long r , f = 1 , n = arr.size() , mod = 100000;
        while(!que.empty()){
            int x = que.front().first , y = que.front().second;
            que.pop();
            for(int i = 0 ; i < n ; i++){
                r = (x*arr[i])%mod;
                if(r==end){
                    return (y+1)%mod;}
                if(visited[r]==0){
                    visited[r]=1;
                    que.push({r,(y+1)%mod});
                }
            }
        }
        //cout<<r<<" "<<end;
        return -1;
    }
//     3
// 3 4 65
// 7 66175

// 4
// 9 12 18 19
// 5 5
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends