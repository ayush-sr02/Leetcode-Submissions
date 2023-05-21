queue<pair<pair<int,int>,int>> q;
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
if(grid[i][j]==1){
q.push({{i,j},0});
}
}
}
while(!q.empty()){
int x=q.front().first.first,y=q.front().first.second;
int dis=q.front().second;
q.pop();
for(auto it:movement){
int xd = x+it.first;
int yd = y+it.second;
if(valid(xd,yd,n,m) and !vis[xd][yd]){
if(grid[xd][yd]==2) return dis;
else if(!grid[xd][yd]){
q.push({{xd,yd},dis+1});
vis[xd][yd]=1;
}
}
}
}
return -1;
}
};