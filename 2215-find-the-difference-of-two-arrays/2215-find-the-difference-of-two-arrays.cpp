class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        set<int> s1,s2;
        for(auto i:nums1) s1.insert(i);
        for(auto i:nums2) s2.insert(i);
        vector<int> v1,v2;
        for(auto i:s1){
            if(!s2.count(i)) v1.push_back(i);
        }
        for(auto i:s2){
            if(!s1.count(i)) v2.push_back(i);
        }
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};