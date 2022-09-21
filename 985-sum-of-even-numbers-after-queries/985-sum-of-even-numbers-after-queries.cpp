class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum=0;
        for(auto i:nums){
            if(i%2==0){
                sum+=i;
            }
        }
        for(int i=0;i<queries.size();i++){
            int idx = queries[i][1];
            int val = queries[i][0];
            if(nums[idx]%2!=0){
                if(val%2!=0){
                    nums[idx]+=val;
                    sum+=nums[idx];
                }
                else{
                    nums[idx]+=val;
                }
                ans.push_back(sum);
            }
            else{
                if(val%2==0){
                    sum+=val;
                    nums[idx]+=val;
                }
                else{
                    sum-=nums[idx];
                    nums[idx]+=val;
                }
                ans.push_back(sum);
            }
        }        
        return ans;
    }
};