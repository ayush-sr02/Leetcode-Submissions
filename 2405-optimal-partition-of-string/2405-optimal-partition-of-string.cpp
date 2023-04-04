class Solution {
public:
    int partitionString(string s) {
        int ans=0;
        unordered_map<char,int> mp;
        int i=0,j=0;
        for(int i=0;i<s.size();i++){
            if(!mp.count(s[i])) mp[s[i]]++;
            else{
                mp.clear();
                mp[s[i]]++;
                ans++;
            }
        }
        ans++;
        return ans;
    }
};