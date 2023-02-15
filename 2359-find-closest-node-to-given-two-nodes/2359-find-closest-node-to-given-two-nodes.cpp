class Solution {
public:
    
    void bfs(vector<int> adj[],int node,vector<int> &dis,vector<int> &vis){
        vis[node]=1;
        queue<pair<int,int>> q;
        q.push({node,0});
        while(!q.empty()){
            int top = q.front().first;
            int level = q.front().second;
            q.pop();
            dis[top]=level;
            for(auto i:adj[top]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push({i,level+1});
                }
            }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        int ans=1e6;
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                adj[i].push_back(edges[i]);
            }
        }
        vector<int> dis1(n,1e8),dis2(n,1e8);
        vector<int> vis1(n,0),vis2(n,0);
        bfs(adj,node1,dis1,vis1);
        bfs(adj,node2,dis2,vis2);
        // for(auto i:dis1) cout<<i<<" ";
        // cout<<endl;
        // for(auto i:dis2) cout<<i<<" ";
        int mx=INT_MAX;
        for(int i=0;i<n;i++){
            if(dis1[i]!=1e8 and dis2[i]!=1e8){
                int temp = max(dis1[i],dis2[i]);
                if(temp<mx){
                    mx=temp;
                    ans=i;
                }
            }
        }
        return ans==1e6?-1:ans;
    }
};