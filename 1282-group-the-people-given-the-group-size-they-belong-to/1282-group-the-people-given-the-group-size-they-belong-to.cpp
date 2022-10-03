class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        vector<vector<int>> ans;
        map<int,vector<int>> mp;
        for(int i=0;i<g.size();i++){
            mp[g[i]].push_back(i);
        }
        for(auto i:mp){
            vector<int> temp;   
            int size = i.first;
            for(int j=0;j<i.second.size();j++){
                temp.push_back(i.second[j]);
                if(temp.size()==size){
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }
        return ans;
    }
};