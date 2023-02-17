class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n=matrix.size(),m=matrix[0].size();
        int rbegin=0,rend=n-1,colbegin=0,colend=m-1;
        int total=m*n;
        int cur=0;
        while(rbegin<=rend and colbegin<=colend){
            if(cur==total) break;
            for(int i=colbegin;i<=colend and cur<total;i++){
                ans.push_back(matrix[rbegin][i]);
                cur++;
            }
            rbegin++;
            for(int i=rbegin;i<=rend and cur<total;i++){
                ans.push_back(matrix[i][colend]);
                cur++;
            }
            colend--;
            for(int i=colend;i>=colbegin and cur<total;i--){
                ans.push_back(matrix[rend][i]);
                cur++;
            }
            rend--;
            for(int i=rend;i>=rbegin and cur<total;i--){
                ans.push_back(matrix[i][colbegin]);
                cur++;
            }
            colbegin++;
        }
        
        return ans;
    }
};