class Solution {
    public void moveZeroes(int[] nums) {
        int n=nums.length;
        int j=0, cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) cnt++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=0) nums[j++]=nums[i];
        }
        for(int i=n-cnt;i<n;i++){
            nums[i]=0;
        }
    }
}