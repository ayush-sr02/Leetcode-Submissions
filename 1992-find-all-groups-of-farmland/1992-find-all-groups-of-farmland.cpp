class Solution {
public:
    
    void solve(vector<vector<int>>& land,int i,int j,int &rmn,int &cmn,int &rmx,int &cmx){
        int n=land.size();
        int m=land[0].size();
        if(i<0 or j<0 or i>=n or j>=m or land[i][j]==2) return;
        if(land[i][j]==0) return;
        land[i][j]=0;
        rmn = min(i,rmn);
        cmn = min(j,cmn);
        rmx = max(i,rmx);
        cmx = max(j,cmx);
        solve(land,i+1,j,rmn,cmn,rmx,cmx);
        solve(land,i,j+1,rmn,cmn,rmx,cmx);
        solve(land,i-1,j,rmn,cmn,rmx,cmx);
        solve(land,i,j-1,rmn,cmn,rmx,cmx);
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        
        int n=land.size();
        int m=land[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1){
                    int rmn=INT_MAX,cmn=INT_MAX,rmx=INT_MIN,cmx=INT_MIN;
                    solve(land,i,j,rmn,cmn,rmx,cmx);
                    vector<int> temp = {rmn,cmn,rmx,cmx};
                    ans.push_back(temp);
                }
            }
        }
        
        return ans;
    }
};