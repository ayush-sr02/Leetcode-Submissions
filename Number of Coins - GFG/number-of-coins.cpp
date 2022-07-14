// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	
	int solve(int *coins,int target,int i,vector<vector<int>>&dp){
	    if(i==0){
	        if(target%coins[i]==0) return target/coins[i];
	        return 1e9;
	    }
	    if(dp[i][target]!=-1) return dp[i][target];
	    int notpick = solve(coins,target,i-1,dp);
	    int pick=1e9;
	    if(target>=coins[i]) pick = 1+solve(coins,target-coins[i],i,dp);
	    return dp[i][target] = min(pick,notpick);
	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes 
	    vector<vector<int>> dp(M,vector<int>(V+1,-1));
	    int ans=solve(coins,V,M-1,dp);
	    return ans==1e9?-1:ans;
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends