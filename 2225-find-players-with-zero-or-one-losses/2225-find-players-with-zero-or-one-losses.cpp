class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        vector<int> zero,one;
        
        map<int,int> mp;
        for(auto it:matches){
            mp[it[1]]++;
        }
        for(auto i:matches){
            if(mp.find(i[0])==mp.end()){
                zero.push_back(i[0]);
                mp[i[0]]=2;
            }
        }
        for(auto i:mp){
            if(i.second==1) one.push_back(i.first);
        }
        sort(begin(zero),end(zero));
        sort(begin(one),end(one));
        ans.push_back(zero);
        ans.push_back(one);
        return ans;
    }
};