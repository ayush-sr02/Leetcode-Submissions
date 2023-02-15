class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>> dis(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++) dis[i][i]=0;
        for(auto i:edges){
            dis[i[0]][i[1]] = i[2];
            dis[i[1]][i[0]] = i[2];
        }
        int ans=0;
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dis[i][j] = min(dis[i][j],(dis[i][via]+dis[via][j]));
                }
            }
        }
        int mx=INT_MAX;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dis[i][j]<=d) cnt++;
            }
            if(cnt<=mx){
                mx=cnt;
                ans=i;
            }
        }
        
        return ans;
    }
};