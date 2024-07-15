//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        if(d*9<s) return "-1";
        string str= "";
        if(s<=9){
            if(d==1) return to_string(s);
            
            str ='1';
            for(int i=0 ; i<d-2 ;i++) str+='0';
            str+=to_string(s-1);
        }
        else{int n= 9;
            while(s){
                string t = to_string(n);
                if(s-n>=1){
                    str+= t;
                    s-=n;
                    d-=1;
                }
                else{
                    break;
                }
                // cout<<str<<" "<<s<<"b";
            }
            
            if(d>1)
            {
                str+=to_string(s-1);
                // cout<<str<<"a";
                d-=1;
                    for(int i= 1; i< d; i++){
                        str+='0';
                    }
                    str+='1';
                d= 0;
            }
            // cout<<str<<" ";
            if(d==1) str+=s+'0';
             reverse(str.begin(),str.end());
        }
       
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends