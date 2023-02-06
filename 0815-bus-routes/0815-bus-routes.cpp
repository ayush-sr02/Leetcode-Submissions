class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int src, int t) {
        unordered_map<int,vector<int>> mp;
        int ans=-1;
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                mp[routes[i][j]].push_back(i);
            }
        }
        queue<pair<int,int>> q;
        q.push({src,0});
        set<int> vis;
        vis.insert(src);
        while(!q.empty()){
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();
            if(node==t) return dis;
            for(auto i:mp[node]){
                for(auto j:routes[i]){
                    if(vis.count(j)==0){
                        q.push({j,dis+1});
                        vis.insert(j);
                    }
                }
                routes[i].clear();
            }
        }
        return ans;
    }
};