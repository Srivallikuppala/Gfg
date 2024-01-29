//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void fun(int o, int c , int n , string &S , vector<string>&vtr){
    
        if(o==n and c==n){
            vtr.push_back(S);
            return;
        }
        if(o<n){
            S+='(';
            fun(o+1,c,n,S,vtr);
            S.pop_back();
        }
        if(o>c){
            S+=')';
            fun(o,c+1,n,S,vtr);
            S.pop_back();
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        string S;
        vector<string>vtr;
        fun(0,0,n,S,vtr);
        return vtr;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends