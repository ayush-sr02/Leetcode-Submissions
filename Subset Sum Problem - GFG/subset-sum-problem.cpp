// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool solve(vector<int> &arr,int target,vector<vector<int>>&dp,int i){
        if(i==0){
            return target==arr[0];
        }
        if(target==0) return true;
        if(dp[i][target]!=-1) return dp[i][target];
        bool notPick = solve(arr,target,dp,i-1);
        bool pick=false;
        if(target>=arr[i]) pick = solve(arr,target-arr[i],dp,i-1);
        return dp[i][target] = notPick||pick;  
    }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        vector<vector<int>> dp(101,vector<int> (100001,-1));
        int n=arr.size();
        return solve(arr,sum,dp,n-1);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends