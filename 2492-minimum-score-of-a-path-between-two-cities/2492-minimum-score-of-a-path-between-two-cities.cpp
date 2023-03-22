class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n+1];
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        queue<int> q;
        q.push(1);
        vector<int> vis(n+1,0);
        vis[1]=1;
        while(!q.empty()){
            int city = q.front();
            q.pop();
            for(auto i:adj[city]){
                if(!vis[i.first]){
                    q.push(i.first);
                    vis[i.first]=1;
                }
            }
        }
        
        int score = INT_MAX;
        for(auto i:roads){
            if(vis[i[0]] and vis[i[1]]){
                score = min(score,i[2]);
            }
        }
        return score;
    }
};