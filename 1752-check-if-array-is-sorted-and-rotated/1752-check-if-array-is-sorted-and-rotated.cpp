class Solution {
public:
    bool check(vector<int>& nums) {
        int idx=0;
        int n=nums.size();
        vector<int> temp(n);
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                idx=i+1;break;
            }
        }
        int k=idx;
        for(int i=0;i<n;i++){
            temp[i] = nums[(k+i)%n];
        }
        return is_sorted(temp.begin(),temp.end());
    }
};