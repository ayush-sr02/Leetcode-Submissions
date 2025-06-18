class Solution {
public:

    vector<pair<int,int>> movement = {{0,1},{0,-1},{1,0},{-1,0}};

    bool valid(int x,int y,int n,int m){
        return x>=0 and y>=0 and x<n and y<m;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({0,{i,j}});
            }
        }
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int curTime = q.front().first;
                int x=q.front().second.first,y=q.front().second.second;
                q.pop();
                ans=max(ans,curTime);
                for(auto i:movement){
                    int xd = x+i.first,yd=y+i.second; 
                    if(valid(xd,yd,n,m) && grid[xd][yd]==1){
                        q.push({curTime+1,{xd,yd}});
                        grid[xd][yd]=2;
                    }   
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};