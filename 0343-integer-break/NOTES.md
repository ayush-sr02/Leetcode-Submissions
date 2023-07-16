if(dp[n]!=-1) return dp[n];
int mx=0;
for(int i=1;i<=n;i++){
int temp = solve(n-i,dp,cur*i);
mx=max(mx,temp);
}
return dp[n]=mx;