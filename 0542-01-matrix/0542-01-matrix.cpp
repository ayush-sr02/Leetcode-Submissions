class Solution {
public:
    
    vector<pair<int,int>> movement = {{-1,0},{1,0},{0,-1},{0,1}};
    
    bool valid(int i,int j,int n,int m){
        return i>=0 and j>=0 and i<n and j<m;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>, int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();
            dis[row][col]=step;
            for(auto it:movement){
                int xd = row+it.first;
                int yd = col+it.second;
                if(valid(xd,yd,n,m) and !vis[xd][yd]){
                    q.push({{xd,yd},step+1});
                    vis[xd][yd]=1;
                }
            }
        }
        return dis;
    }
};