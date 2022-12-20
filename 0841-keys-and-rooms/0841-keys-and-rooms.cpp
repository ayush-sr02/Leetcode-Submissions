class Solution {
public:
    
    void dfs(vector<vector<int>>& rooms,int node,vector<int> &vis){
        vis[node]=true;
        for(int i=0;i<rooms[node].size();i++){
            if(!vis[rooms[node][i]]) dfs(rooms,rooms[node][i],vis);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n,false);
        vis[0]=true;
        dfs(rooms,0,vis);
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};