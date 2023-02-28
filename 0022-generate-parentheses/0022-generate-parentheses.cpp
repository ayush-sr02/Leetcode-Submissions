class Solution {
public:
    
    vector<string> ans;
    
    void backtrack(int open, int close, int n, string s){
        if(s.size()==n*2){
            ans.push_back(s);
            return;
        }
        if(open<n){
            backtrack(open+1,close,n,s+'(');
        }
        if(close<open) {
            backtrack(open,close+1,n,s+')');
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string s="";
        int open=0,close=0;
        backtrack(open, close, n, s);
        return ans;
    }
};