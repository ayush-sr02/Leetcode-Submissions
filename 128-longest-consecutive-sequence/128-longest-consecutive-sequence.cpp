class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        for(auto i:nums) mp[i]++;
        int ans=0;
        int cnt=1;
        for(auto i:mp){
            if(mp.find(i.first+1)!=mp.end()) cnt++;
            else cnt=1;
            ans=max(ans,cnt);
        }
        return ans;
    }
};