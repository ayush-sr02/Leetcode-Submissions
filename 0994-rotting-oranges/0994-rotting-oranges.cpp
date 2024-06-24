class Solution {
public:
    
    bool isvalid(int i,int j, int n, int m){
        return i>=0 and i<n and j>=0 and j<m;
    }
    
    vector<pair<int,int>> v = {{-1,0},{1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(), m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> p = q.front();
                q.pop();
                for(auto it:v){
                    int dx = p.first+it.first;
                    int dy = p.second+it.second;
                    if(isvalid(dx,dy,n,m)){
                        if(grid[dx][dy]==1){
                            grid[dx][dy]=-1;
                            q.push({dx,dy});
                        }
                    }
                }
            }
            ans++;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans==0?0:ans-1;
    }
};