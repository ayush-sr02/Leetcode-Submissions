class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(auto i:nums) mp[i]++;
        vector<vector<int>> bucket(n+1);
        vector<int> ans;
        for(auto [num,cnt]:mp){
            bucket[cnt].push_back(num);
        }
        for(int i=n;i>=0 && ans.size()<k;i--){
            if(bucket[i].size()!=0){
                for(int j=0;j<bucket[i].size() && ans.size()<k;j++){
                    ans.push_back(bucket[i][j]);
                }
            }
        }
        return ans;
    }
};