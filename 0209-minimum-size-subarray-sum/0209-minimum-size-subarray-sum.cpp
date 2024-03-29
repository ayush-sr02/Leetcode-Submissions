class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=1e9;
        int i=0,j=0,n=nums.size();
        int cur=0;
        while(j<n){
            cur+=nums[j];
            if(cur<target) j++;
            else{
                while(i<n and cur>=target){
                    ans=min(ans,j-i+1);
                    cur-=nums[i];
                    i++;
                }
                j++;
            }
        }
        
        return ans==1e9?0:ans;
    }
};