class Solution {
public:
    vector<pair<int,int>> movement = {{0,1},{0,-1},{1,0},{-1,0}};
    
    bool valid(int x,int y,int n,int m){
        return x>=0 and y>=0 and x<n and y<m;
    }
    
    void bfs(vector<vector<char>>& grid,int i,int j,vector<vector<int>> &vis,int n,int m){
        queue<pair<int,int>> q;
        q.push(make_pair(i,j));
        vis[i][j]=1;
        while(!q.empty()){
            auto node = q.front();
            int x=node.first,y=node.second;
            q.pop();
            for(auto i:movement){
                int xd = x+i.first;
                int yd = y+i.second;
                if(valid(xd,yd,n,m)){
                    if(!vis[xd][yd] and grid[xd][yd]=='1'){
                        q.push(make_pair(xd,yd));
                        vis[xd][yd]=1;
                    }
                }
                
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' and !vis[i][j]){
                    bfs(grid,i,j,vis,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};