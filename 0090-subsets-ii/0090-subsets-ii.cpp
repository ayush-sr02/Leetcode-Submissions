class Solution {
public:
    vector<vector<int>> ans;
    // set<vector<int>> st;
    void solve(vector<int>& nums, int n, int i, vector<int>& cur){
        if(i==n){
            ans.push_back(cur);
            // st.insert(cur);
            return;
        }
        cur.push_back(nums[i]);
        solve(nums, n, i+1, cur);
        cur.pop_back();
        while(i<n-1 and nums[i]==nums[i+1]) i++;
        solve(nums, n, i+1, cur);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums), end(nums));
        vector<int> cur;
        solve(nums, n, 0, cur);
        // for(auto i: st) ans.push_back(i);
        return ans;        
    }
};