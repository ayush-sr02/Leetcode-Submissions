class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=0,cur=0;
        for(auto i:nums){
            if(cur==0) ans=i;
            if(i==ans) cur++;
            else cur--;
        }
        return ans;
    }
};