class Solution {
public:
    
    vector<pair<int,int>> movement = {{0,1},{0,-1},{1,0},{-1,0}};
    
    bool valid(int x,int y,int n,int m){
        return x<n and y<m and x>=0 and y>=0;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> vis(n,vector<int> (m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(mat[i][j]==0){
                     q.push(make_pair(i,j));
                     vis[i][j]=0;
                 }
            }
        }
        while(!q.empty()){

            auto node = q.front();
            int x=node.first,y=node.second;
            q.pop();
            for(auto i:movement){
                int xd = x+i.first;
                int yd = y+i.second;
                if(valid(xd,yd,n,m) and vis[xd][yd]==-1){
                    q.push(make_pair(xd,yd));
                    vis[xd][yd] = vis[x][y]+1;
                }
            }
        }
        return vis;
    }
};