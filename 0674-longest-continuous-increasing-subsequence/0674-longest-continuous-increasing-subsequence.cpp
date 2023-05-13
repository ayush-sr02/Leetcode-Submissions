class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans=0;
        int cur=0;
        int prev=-1;
        for(int i=0;i<nums.size();i++){
            if(prev==-1 or nums[i]>nums[prev]){
                cur++;
                ans=max(ans,cur);
                prev=i;
            }else{
                cur=1;
                prev=i;
            }
        }
        return ans;
    }
};