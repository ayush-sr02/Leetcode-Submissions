class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> s;
        vector<int> ans;
        for(auto i:nums){
            if(s.count(i)!=0) ans.push_back(i);
            s.insert(i);
        }
        return ans;
    }
};