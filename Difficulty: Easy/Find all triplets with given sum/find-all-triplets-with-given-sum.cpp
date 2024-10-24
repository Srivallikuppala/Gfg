//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &arr, int target) {
        // Code here
         set<vector<int>> resSet;
    int n = arr.size();
    unordered_map<int, vector<pair<int, int>>> mp;

    // Store sum of all the pairs with their indices
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            mp[arr[i] + arr[j]].push_back({i, j});
    }

      for (int i = 0; i < n; i++) {

        // Find remaining value to get sum equal to target
        int rem = target - arr[i];
        if (mp.find(rem) != mp.end()) {
            vector<pair<int, int>> pairs = mp[rem];
            for (auto p : pairs) {
              
                  // Ensure no two indices are same in triplet
                if (p.first != i && p.second != i) {
                    vector<int> curr = {i, p.first, p.second};
                    sort(curr.begin(), curr.end());
                    resSet.insert(curr);
                }
            }
        }
    }
    vector<vector<int>> res;
    for(auto a: resSet){
         vector<int> curr = {arr[a[0]],arr[a[1]],arr[a[2]]};
         sort(curr.begin(),curr.end());
        res.push_back(curr);
    }

   
    return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;

        vector<vector<int>> res = ob.threeSum(arr, target);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends