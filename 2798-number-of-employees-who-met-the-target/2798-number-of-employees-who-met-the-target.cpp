class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        sort(begin(hours),end(hours));
        int n=hours.size();
        for(int i=0;i<hours.size();i++){
            if(hours[i]>=target) return n-i;
        }
        return 0;
    }
};