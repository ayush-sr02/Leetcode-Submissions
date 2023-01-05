class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=0;
        int end=points[0][1];
        for(auto i:points) cout<<i[0]<<" ";
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=end){
                end=min(end,points[i][1]);
            }else{
                ans++;
                end = points[i][1];
            }
        }
        return ans+1;
    }
};