class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char,int> mp;
        for(auto i:sentence) mp[i]++;
        return mp.size()==26;
    }
};