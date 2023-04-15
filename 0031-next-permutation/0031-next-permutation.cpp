class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int x,y,z;
        for(x=nums.size()-2;x>=0;x--){
            if(nums[x]<nums[x+1]) break;
        }
        if(x<0){
            reverse(begin(nums),end(nums));return;
        }
        for(y=nums.size()-1;y>x;y--){
            if(nums[y]>nums[x]){
                swap(nums[y],nums[x]);
                reverse(nums.begin()+x+1,nums.end());
                return;
            }
        }
    }
};