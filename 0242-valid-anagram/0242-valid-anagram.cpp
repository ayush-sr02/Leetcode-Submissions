class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26,0);
        int n=s.size(),m=t.size();
        for(int i=0;i<max(n,m);i++){
            if(i<n){
                freq[s[i]-'a']++;
            }
            if(i<m){
                freq[t[i]-'a']--;
            }
        }
        int sum=0;
        for(auto i:freq){
            if(i!=0) return false;
        }
        return true;
    }
};