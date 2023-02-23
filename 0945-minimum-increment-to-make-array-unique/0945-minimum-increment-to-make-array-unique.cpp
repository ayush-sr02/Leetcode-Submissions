class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ans=0;
        set<int> s;
        sort(begin(nums),end(nums));
        for(int i=0;i<nums.size();i++){
            if(s.count(nums[i])==0){
                s.insert(nums[i]);
            }else{
                int temp = nums[i];
                nums[i]=nums[i-1]+1;
                ans+=(nums[i]-temp);
                s.insert(nums[i]);
            }
        }
        return ans;
    }
};