static bool comp(vector<int> a,vector<int> b){
    return a[1]<b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        sort(begin(intervals),end(intervals),comp);
        
        vector<int> temp = intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<temp[1]){
                ans++;
                continue;
            }else{
                temp=intervals[i];
            }
        }
        return ans;
    }
};