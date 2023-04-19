class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int ans=INT_MAX;
        int n = graph.size();
        for(int i=0;i<n;i++){
            vector<vector<int>> dp(1<<n,vector<int> (n,-1));
            queue<pair<int,int>> q;
            q.push({1<<i,i});
            dp[1<<i][i]=0;
            
            while(!q.empty()){
                int msk = q.front().first;
                int node = q.front().second;
                q.pop();
                if(msk==(1<<n)-1) ans=min(ans,dp[msk][node]);
                
                for(auto it:graph[node]){
                    int newMask = msk|(1<<it);
                    if(dp[newMask][it]==-1){
                        q.push({newMask,it});
                        dp[newMask][it] = dp[msk][node]+1;
                    }
                }
            }
        }
        return ans;
    }
};