class Solution {
public:
    
    void dfs(vector<int> adj[],int node, unordered_set<int>&st,vector<int>&vis){
        st.insert(node);
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(adj,it,st,vis);
            }
        }
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<int> adj[n];
        for(auto i:pre){
            adj[i[0]].push_back(i[1]);
        }
        vector<bool> ans;
        map<int,unordered_set<int>> mp;
        for(int i=0;i<n;i++){
            unordered_set<int> st;
            vector<int> vis(n,0);
            dfs(adj,i,st,vis);
            mp[i]=st;
        }
        
        for(auto i:queries){
            if(mp[i[0]].count(i[1])) ans.push_back(true);
            else ans.push_back(false);
        }
        
        return ans;
    }
};