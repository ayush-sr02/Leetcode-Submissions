class Solution {
public:
    vector<pair<int,int>> idx = {{-1,-1},{-1,1},{1,-1},{1,1},{0,1},{0,-1},{1,0},{-1,0}};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0) return -1;
        queue<pair<int,int>> q;
        int m=grid.size();
        int ans=INT_MAX;
        q.push({0,0});
        int curStep=1;
        vector<vector<int>> vis(m,vector<int> (m,0));
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x==m-1 && y==m-1){
                    ans=min(ans,curStep);
                }
                for(auto j:idx){
                    int xx=x+j.first;
                    int yy=y+j.second;
                    if(xx>=0 && xx<m && yy>=0 && yy<m && !vis[xx][yy] && grid[xx][yy]==0){
                        vis[xx][yy]=1;
                        q.push({xx,yy});
                    }
                }
            }
            curStep++;
        }
        ans=(ans==INT_MAX?-1:ans);
        return ans;
    }
};