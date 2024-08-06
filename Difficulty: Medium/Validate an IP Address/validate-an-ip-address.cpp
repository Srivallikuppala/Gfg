//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0

You are required to complete this method */
class Solution {
  public:
    int isValid(string str) {
        // code here
        int n= str.size(), t= 1, k= 0, x= 0, p= 0;
        for(int i= 0; i< n; i++){
            // cout<<x<<" ";
            if(t==1){
                if(str[i]=='.'){
                    p+=1;
                    if(p>3)return false;
                    if((x==0 and k==0) or (x< 0 or x>255))return false;
                    x= 0;
                    k= 0;
                }
                else if(str[i]=='0' and x==0) k=1;
                else{
                    if(k==1) return false;
                    x=(x*10)+(int(str[i])-48);
                }
            }
        }
        if((x==0 and k==0) or p!=3 or (x< 0 or x>255))return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends