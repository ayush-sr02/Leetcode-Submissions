class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>&c,int t,int i,vector<int>&temp){
        if(t<0) return;
        if(i==c.size()){
            if(t==0) ans.push_back(temp);
            return;
        }
        if(c[i]<=t){
            temp.push_back(c[i]);
            solve(c,t-c[i],i+1,temp);
            while(i<c.size()-1 and c[i]==c[i+1]) i++;
            temp.pop_back();
        }
        solve(c,t,i+1,temp);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<int> temp;
        sort(begin(c),end(c));
        solve(c,t,0,temp);
        return ans;
    }
};