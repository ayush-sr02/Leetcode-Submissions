class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> mp1,mp2;
        int cnt=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            vector<int> v;
            for(int j=0;j<m;j++){
                v.push_back(grid[i][j]);
            }
            mp1[v]++;
        }
        for(int i=0;i<n;i++){
            vector<int> v;
            for(int j=0;j<n;j++){
                v.push_back(grid[j][i]);
            }
            if(mp1.find(v)!=mp1.end()){
                
                cnt+=mp1[v];
            }
            mp2[v]++;
        }
        return cnt;
    }
};