class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> v=nums;
        for(auto i:nums) v.push_back(i);
        vector<int> ans;
        for(int i=0;i<n;i++){
            bool flag=true;
            int cur=-1;
            for(int j=i+1;j<i+n;j++){
                if(v[j]>nums[i]){
                    cur=v[j];
                    break;
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }
};