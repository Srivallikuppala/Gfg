//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
        vector<string> vtr;
        string c,d,x,p;
        float a,b;
        float maxi = 0.0;
        for(auto it:str){
            if(it=='/'){
            
                a = static_cast<float>(stoi(x));
                p+=x+'/';
                x = "";
            }
            else if(it==','){
                b = static_cast<float>(stoi(x));
                maxi = a/b;
                p+=x;
                vtr.push_back(p);
                p = "";
                x = "";
            }
            else{
                x+=it;
            }
        }
        p+=x;
        vtr.push_back(p);
        if (a/static_cast<float>(stoi(x))==maxi) return "equal";
        else if((a/static_cast<float>(stoi(x))>maxi)) return vtr[1].substr(1,vtr[1].size()-1);
        return vtr[0];
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends