class Solution {
public:
    bool search(vector<int>& nums, int target) {
        set<int> st(begin(nums),end(nums));
        return st.count(target);
    }
};