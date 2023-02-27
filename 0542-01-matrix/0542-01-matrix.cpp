class Solution {
public:
    
    vector<vector<int>> movement = {{0,1},{0,-1},{1,0},{-1,0}};
    
    bool isValid(int i,int j,int n,int m){
        return i>=0 and j>=0 and i<n and j<m;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }
        vector<vector<int>> ans(n,vector<int> (m,0));
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int time=q.front().second;
            q.pop();
            for(auto i:movement){
                int xd=x+i[0];
                int yd=y+i[1];
                if(isValid(xd,yd,n,m) and mat[xd][yd]==1){
                    q.push({{xd,yd},time+1});
                    mat[xd][yd]=0;
                    ans[xd][yd]=time+1;
                }
            }
        }
        return ans;
    }
};