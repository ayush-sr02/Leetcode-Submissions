class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> s;
        for(auto i:nums) s.insert(i);
        int req=s.size();
        int ans=0;
        for(int i=0;i<nums.size();i++){
            set<int> st;
            for(int j=i;j<nums.size();j++){
                st.insert(nums[j]);
                if(st.size()==req) ans++;
            }
        }
        return ans;
    }
};