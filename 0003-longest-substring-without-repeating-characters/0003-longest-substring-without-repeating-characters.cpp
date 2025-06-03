class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,n=s.size(),ans=0;
        unordered_map<char,int> mp;
        while(j<n){
            if(mp.find(s[j])==mp.end()){
                mp[s[j]]++;
            }else{
                while(mp[s[j]]==1 and i<j){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
                mp[s[j]]++;
            }
            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};