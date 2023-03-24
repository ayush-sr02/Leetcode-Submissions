class Solution {
public:
    vector<vector<string>> ans;
    bool isPalin(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    
    void solve(string &s,int idx,vector<string> &v){
        if(idx==s.size()){
            ans.push_back(v);return;
        }
        
        for(int i=idx;i<s.size();i++){
            if(isPalin(s,idx,i)){
                v.push_back(s.substr(idx,i-idx+1));
                solve(s,i+1,v);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> store;
        solve(s,0,store);
        return ans;
    }
};