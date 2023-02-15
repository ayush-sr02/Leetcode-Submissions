class Solution {
public:
void bfs(vector<int> adj[],vector<int>&vis,vector<int>dis,int node){
vis[node]=1;
dis[node]=0;
queue<int> q;
int x=1;
while(!q.empty()){
int nd = q.front();
q.pop();
for(auto i:adj[nd]){
if(!vis[i]){
q.push(i);
dis[i]=x;
}
}
x++;
}
}
int closestMeetingNode(vector<int>& edges, int node1, int node2) {
int ans=0;
int n=edges.size();
vector<int> adj[n];
for(int i=0;i<edges.size();i++)
if(edges[i]!=-1){
adj[i].push_back(edges[i]);
}
}
vector<int> dis1(n,0);
vector<int> dis2(n,0);
vector<int> vis1(n,0),vis2(n,0);
​
bfs(adj,vis1,dis1,node1);
bfs(adj,vis2,dis2,node2);
for(auto i:dis1) cout<<i<<" ";
return ans;
}
};