class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt=0;
        int zero=0;
        int i=0,j=0;
        int n=nums.size();
        int ans=0;
        while(j<n){
            cnt++;
            if(nums[j]==0) zero++;
            while(zero>k){
                if(nums[i]==0) zero--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};