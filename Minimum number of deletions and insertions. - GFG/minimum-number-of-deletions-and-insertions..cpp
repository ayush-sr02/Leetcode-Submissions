//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n=str1.size(),m=str2.size();
	    vector<vector<int>> dp(n+1,vector<int> (m+1));
	    
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=m;j++){
	            if(i==0 or j==0) dp[i][j]=0;
	            else if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
	            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    int mx=max(n,m),mn=min(n,m);
        int del = mx-dp[n][m];
        int ins = mn-dp[n][m];
        return del+ins;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends