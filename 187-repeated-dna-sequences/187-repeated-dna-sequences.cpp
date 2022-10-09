class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.size()<10) return ans;
        map<string,int> mp;
        for(int i=0;i<s.size()-9;i++){
            string temp = s.substr(i,10);
            mp[temp]++;
        }
        for(auto i:mp){
            if(i.second>1) ans.push_back(i.first);
        }
        return ans;
    }
};