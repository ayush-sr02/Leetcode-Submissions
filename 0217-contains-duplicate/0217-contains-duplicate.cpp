class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st (begin(nums),end(nums));
        return st.size()!=nums.size();
    }
};