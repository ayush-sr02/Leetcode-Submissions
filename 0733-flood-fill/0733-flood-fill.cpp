class Solution {
public:
    
    bool isValid(int x,int y,int n,int m){
        return x>=0 and y>=0 and x<n and y<m;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int n=image.size(),m=image[0].size();
        vector<pair<int,int>> movement = {{0,-1},{1,0},{0,1},{-1,0}};
        vector<vector<int>> vis(n,vector<int> (m,0));
        q.push(make_pair(sr,sc));
        vis[sr][sc]=1;
        int temp=image[sr][sc];
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            image[top.first][top.second]=color;
            for(auto i:movement){
                int x = top.first+i.first;
                int y = top.second+i.second;
                if(isValid(x,y,n,m) and image[x][y]==temp and !vis[x][y]){
                    q.push(make_pair(x,y));
                    vis[x][y]=1;
                }
            }
        }
        return image;
    }
};