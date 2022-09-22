class Solution {
public:
    
    vector<pair<int,int>> movement = {{0,1},{0,-1},{1,0},{-1,0}};
    
    bool valid(int i,int j,int n,int m){
        return i>=0 and j>=0 and i<n and j<m;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }
        int l=0;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int x=front.first.first;
            int y=front.first.second;
            int level=front.second;
            l=max(l,level);
            for(auto xx:movement){
                int xd = xx.first+x;
                int yd = xx.second+y;
                if(valid(xd,yd,n,m) and !vis[xd][yd] and grid[xd][yd]==1){
                    q.push({{xd,yd},level+1});
                    grid[xd][yd]=2;
                    vis[xd][yd]=1;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        
        return l;
    }
};