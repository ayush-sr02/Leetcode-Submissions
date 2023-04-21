class Solution {
public:
    int n,m;
    vector<pair<int,int>> movement = {{0,1},{0,-1},{1,0},{-1,0}};
    
    bool bfs(vector<vector<char>> &grid,vector<vector<int>>&vis,int i,int j,int parX,int parY,char ch){
        vis[i][j]=1;
        bool detect = false;
        for(auto it:movement){
            int newX = i+it.first;
            int newY = j+it.second;
            //valid index
            if(newX>=0 and newY>=0 and newX<n and newY<m){
                //has same character
                if(grid[newX][newY]==ch){
                    //not equal to the last visited index
                    if(!(newX==parX and newY==parY)){
                        //if already visited then there is cycle
                        if(vis[newX][newY]) return true;
                        else detect |= bfs(grid,vis,newX,newY,i,j,ch);
                    }
                }
            }
        }
        return detect;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j])
                    if(bfs(grid,vis,i,j,i,j,grid[i][j])==true) return true;
            }
        }
        return false;
    }
};