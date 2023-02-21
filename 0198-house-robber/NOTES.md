class Solution {
public int rob(int[] nums) {
int[] dp = new  int[nums.length+1];
Arrays.fill(dp,-1);
return func(0, 0, nums,dp);
}
public int func(int i, int sum, int[] arr,int[] dp){
if(i>=arr.length) return 0;
if(i==arr.length-1)
return arr[i];
if(dp[i]!=-1) return dp[i];
int a = arr[i];
if(i+2<arr.length)
a += func(i+2, sum+arr[i], arr,dp);
int b = func(i+1, sum, arr,dp);
return dp[i] = Math.max(a,b);
}
}