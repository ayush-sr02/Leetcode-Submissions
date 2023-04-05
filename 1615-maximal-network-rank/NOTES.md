class Solution {
public:
int maximalNetworkRank(int n, vector<vector<int>>& roads) {
vector<int> nodeCount(n,0);
set<vector<int>> st(begin(roads),end(roads));
for(auto i:roads){
nodeCount[i[0]]++;
nodeCount[i[1]]++;
}
int ans=0;
for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
int cur = nodeCount[i]+nodeCount[j];
if(st.count({i,j}) or st.count({j,i})) cur-=1;
ans=max(ans,cur);
}
}
return ans;
}
};