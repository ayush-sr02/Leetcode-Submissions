//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
	public:
	int mod = 1e9+7;
	int solve(int i,int sum,int arr[],vector<vector<int>> &dp){
	    if(i==0){
	        if(sum==0 and arr[i]==0) return 2;
	        if(sum==arr[i] or sum==0) return 1;
	        return 0;
	    }
	    if(dp[i][sum]!=-1) return dp[i][sum];
	    int notPick = solve(i-1,sum,arr,dp);
	    int pick = 0;
	    if(arr[i]<=sum) pick = solve(i-1,sum-arr[i],arr,dp);
	    return dp[i][sum] = ((pick%mod)+(notPick%mod))%mod;
	}
	
	int perfectSum(int arr[], int n, int sum){
        // Your code goes here
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return solve(n-1,sum,arr,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends