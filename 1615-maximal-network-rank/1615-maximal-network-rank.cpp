class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        set<vector<int>> st(begin(roads),end(roads));
        for(auto i:roads){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cur = adj[i].size()+adj[j].size();
                if(st.count({i,j}) or st.count({j,i})) cur-=1;
                ans=max(ans,cur);
            }
        }
        return ans;
    }
};