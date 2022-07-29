class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        set<char> st;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])==mp.end()){
                if(st.count(t[i])==0){
                    mp[s[i]]=t[i];
                    st.insert(t[i]);
                }
                else return false;
            }
            else if(mp[s[i]]!=t[i]) return false;
        }
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(auto i:words){
            if(isIsomorphic(i,pattern)) ans.push_back(i);
        }
        
        return ans;
    }
};