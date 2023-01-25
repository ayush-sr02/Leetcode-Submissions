class Solution {
public:
    
    vector<vector<int>> ans;
    
    void solve(vector<int>&c,int t,int i,vector<int> &temp){
        if(i==c.size()){
            if(t==0) ans.push_back(temp);
            return;
        }
        if(t<0) return;
        temp.push_back(c[i]);
        solve(c,t-c[i],i,temp);
        temp.pop_back();
        solve(c,t,i+1,temp);
    }    
    
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<int> temp;
        // int sum=0;
        solve(c,t,0,temp);
        return ans;
    }
};