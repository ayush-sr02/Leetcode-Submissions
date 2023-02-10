​
class Solution {
public:
#define pi pair<int,int>
vector<pair<int,int>> movement = {{0,1},{0,-1},{-1,0},{1,0}};
bool valid(int i,int j,int n,int m){
return i>=0 and j>=0 and i<n and j<m;
}
int minimumEffortPath(vector<vector<int>>& heights) {
int n=heights.size(),m=heights[0].size();
priority_queue<pair<int,pi>,vector<pair<int,pi>>,greater<pair<int,pi>>> pq;
pq.push({0,{0,0}});
vector<vector<int>> dis(n,vector<int> (m,1e9));
vector<vector<int>> parent(n,vector<int>(m,0));
vector<vector<int>> vis(n,vector<int>(m,0));
​
for(int i=0;i<n;i++){
for(int j=0;j<m;j++) parent[i][j] = (i*10)+j;
}
​
dis[0][0]=0;
vis[0][0]=1;
int ans=0;
while(!pq.empty()){
int x = pq.top().second.first;
int y = pq.top().second.second;
int dist = pq.top().first;
if(x==n-1 and y==m-1) break;
pq.pop();
for(auto i:movement){
int xd = x+i.first;
int yd = y+i.second;
if(valid(xd,yd,n,m) and !vis[xd][yd]){
if(abs(heights[xd][yd]-heights[x][y])<dis[xd][yd]){
vis[xd][yd]=1;
dis[xd][yd] = abs(heights[xd][yd]-heights[x][y]);
pq.push({abs(heights[xd][yd]-heights[x][y]),{xd,yd}});
parent[xd][yd] = (x*10)+y;
}
}
}
}
for(int i=0;i<n;i++){
for(int j=0;j<m;j++) cout<<parent[i][j]<<" ";
cout<<endl;
}
return ans;
}
};