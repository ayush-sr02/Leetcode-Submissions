//Multi-source BFS

class Solution {
public:
    bool valid(int i,int j,int n,int m){
        return i>=0 and j>=0 and i<n and j<m;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size(),m=maze[0].size();
        queue<pair<int,int>> q;
        vector<pair<int,int>> movement = {{0,-1},{-1,0},{0,1},{1,0}};
        
        // Push all the points in the queue which are on the border and a valid exit.
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or j==0 or i==n-1 or j==m-1){
                    vector<int> v = {i,j};
                    if(maze[i][j]=='.' and v!=entrance) q.push({i,j});
                }
            }
        }
        
        int ans=0;
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(i==entrance[0] and j==entrance[1]) return ans;
                //mark as visited by changing . to + (saves the extra space for a visited array).
                
                maze[i][j]='+';
                for(auto it:movement){
                    int xd = i+it.first;
                    int yd = j+it.second;
                    if(valid(xd,yd,n,m) and maze[xd][yd]=='.'){
                        q.push(make_pair(xd,yd));
                        maze[xd][yd]='+';
                    }
                }
            }
            ans++;
        }
        
        // No valid path from entrance to a border so return -1.
        return -1;
    }
};