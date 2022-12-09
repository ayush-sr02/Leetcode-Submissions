class Solution {
public:
    
    bool isValid(int i,int j,int n,int m){
        return i>=0 and j>=0 and i<n and j<m;
    }
    
    void bfs(int i,int j,int n,int m,vector<vector<char>>& grid){
        vector<pair<int,int>> movement = {{-1,0},{0,1},{1,0},{0,-1}};
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j]='0';
        while(!q.empty()){
            auto top = q.front();q.pop();
            grid[top.first][top.second]=0;
            for(auto i:movement){
                int x=top.first+i.first,y=top.second+i.second;
                if(isValid(x,y,n,m) and grid[x][y] == '1'){
                    q.push(make_pair(x,y));
                    grid[x][y]=0;
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    bfs(i,j,n,m,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};