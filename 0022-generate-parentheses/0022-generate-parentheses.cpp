class Solution {
public:
    vector<string> ans;

    void solve(int i,string cur,int n,int left,int right){
        if(cur.size()==2*n){
            if(left==right)
            ans.push_back(cur);
            return;
        }
        solve(i+1,cur+'(',n,left+1,right);
        if(left>right) solve(i+1,cur+')',n,left,right+1);
    }

    vector<string> generateParenthesis(int n) {
        string cur="";
        int left=0,right=0;
        solve(0,cur,n,left,right);
        return ans;
    }
};