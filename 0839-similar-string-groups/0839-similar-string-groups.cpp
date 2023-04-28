class Solution {
public:
    
    bool similar(string &s,string &t){
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]) cnt++;
            if(cnt>2) return false;
        }
        return true;
    }
    
    void dfs(int node,set<int> adj[],vector<int> &vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int ans=0;
        int n=strs.size();
        set<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(similar(strs[i],strs[j])){
                    adj[i].insert(j);
                    adj[j].insert(i);
                }
            }
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                ans++;
            }
        }
        return ans;
    }
};