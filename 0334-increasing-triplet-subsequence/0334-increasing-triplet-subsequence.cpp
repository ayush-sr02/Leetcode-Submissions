class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3) return false;
        set<int> s;
        for(auto i:nums) s.insert(i);
        if(s.size()<3) return false;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]<nums[j]){
                    for(int k=j+1;k<n;k++){
                        if(nums[j]<nums[k]){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};