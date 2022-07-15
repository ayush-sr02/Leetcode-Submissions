class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int cnt=0;
        vector<int> ans;
        for(auto it:nums){
            if(it<pivot) ans.push_back(it);
            if(it==pivot) cnt++;
        }
        while(cnt--) ans.push_back(pivot);
        for(auto it:nums) if(it>pivot) ans.push_back(it);
        
        return ans;
    }
};