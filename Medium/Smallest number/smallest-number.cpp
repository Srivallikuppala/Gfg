//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


#include<string>
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here
        if(D*9<S) return "-1";
        int c;
        if(S%9==0) c = (S/9)-1;
        else c = S/9;
        if(S!=9)S = S%9;
        else S = 9;
        string s;
        while(c){
            s+='9';
            c-=1;
            D-=1;
        }
        if(D==1)s+=to_string(S);
        else{
            s+=to_string(S-1);
            D-=1;
            while(D>1){
                s+= "0";
                D-=1;
            }
            s+="1";
        }
        reverse(s.begin(),s.end());
        return s;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends