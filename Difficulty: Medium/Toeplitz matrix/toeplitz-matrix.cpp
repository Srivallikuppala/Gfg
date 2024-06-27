//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToepliz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToepliz(a);

        if (b == true)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



bool isToepliz(vector<vector<int>>& mat) {
    // code here
    int n= mat.size(), m= mat[0].size();
    for(int i= 0; i< m; i++){
        int c= i+1;
        for(int j= 1; j< n and c<m; j++){
            // cout<<i<<" "<<j<<" "<<c<<endl;
            if(mat[0][i]!=mat[j][c]) return 0;
            
            c+=1;
        }
    }
    for(int i= m-1; i>= 0; i--){
        int c= i-1;
        for(int j= n-2; j>= 0 and c>=0; j--){
            // cout<<i<<" "<<j<<" "<<c<<endl;
            if(mat[n-1][i]!=mat[j][c]) return 0;
            
            c-=1;
        }
    }
    return 1;
}