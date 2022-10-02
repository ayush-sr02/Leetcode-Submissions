class Solution {
public:
    
    int find(int n,int m,int i,int j,vector<vector<int>>&grid){
        int sum=0;
        sum+=grid[i][j]+grid[i][j+1]+grid[i][j+2];
        sum+=grid[i+1][j+1];
        sum+=grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
        return sum;
    }
    
    int maxSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(n<3 or m<3) return 0;
        int mx=-1;
        int i=0,j=0;
        for(i=0;i<n-2;i++){
            for(j=0;j<m-2;j++){
                int sum = find(n,m,i,j,grid);
                mx=max(mx,sum);
            }
        }
        return mx;
    }
};