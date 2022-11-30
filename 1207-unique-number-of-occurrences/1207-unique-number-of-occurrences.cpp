class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        set<int> s;
        for(auto i:arr) mp[i]++;
        for(auto i:mp){
            if(s.count(i.second)) return false;
            s.insert(i.second);
        }
        return true;
    }
};