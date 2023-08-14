class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        vector<vector<int>> ans;
        int n=intervals.size();
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=intervals[i-1][1]){
                intervals[i][0] = intervals[i-1][0];
                intervals[i][1] = max(intervals[i][1],intervals[i-1][1]);
            }else{
                ans.push_back(intervals[i-1]);
            }
        }
        ans.push_back(intervals[n-1]);
        return ans;
    }
};