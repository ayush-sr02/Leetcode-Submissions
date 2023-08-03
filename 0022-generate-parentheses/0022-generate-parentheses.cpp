class Solution {
public:
    
    vector<string> ans;
    
    void solve(int n,int open,int close,string cur){
        if(cur.size()==n){
            ans.push_back(cur);
        }
        if(open<n/2) solve(n,open+1,close,cur+'(');
        if(open>close) solve(n,open,close+1,cur+')');
        
    }
    
    vector<string> generateParenthesis(int n) {
        solve(n*2,0,0,"");
        return ans;
    }
};