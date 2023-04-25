class Solution {
public:
    #define ll long long
    
    long long appealSum(string s) {
        vector<ll> freq(26,-1);
        ll ans=0;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a'] = i;
            for(int j=0;j<26;j++){
                ans+=freq[j]+1;
            }
        }
        return ans;
    }
};