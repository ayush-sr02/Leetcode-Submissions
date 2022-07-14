// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
  
  int solve(int *arr,vector<vector<int>>&dp,int i,int target){
      if(target==0) return dp[i][target] = 1;
      if(i==0) return dp[i][target] = target==arr[i];
      if(dp[i][target]!=-1) return dp[i][target];
      bool notPick = solve(arr,dp,i-1,target);
      bool pick = false;
      if(target>=arr[i]) pick = solve(arr,dp,i-1,target-arr[i]);
      return dp[i][target] = pick||notPick;
  }
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++) sum+=arr[i];
	    vector<vector<int>> dp(n,vector<int> (sum+1,-1));
	    for(int i=0;i<=sum;i++){
	        solve(arr,dp,n-1,i);
	    }
	    int mn=1e9;
	    for(int i=0;i<=sum/2;i++){
	        if(dp[n-1][i]==1){
	            mn = min(mn,abs(sum-2*i));
	        }
	    }
	    return mn;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends