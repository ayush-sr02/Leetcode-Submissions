class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        int i=0,j=0;
        deque<int> dq;
        while(i<n and j<n){
            while(!dq.empty() and nums[dq.back()]<nums[j]) dq.pop_back();
            dq.push_back(j);
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                ans.push_back(nums[dq.front()]);
                if(i==dq.front()) dq.pop_front();
                i++;j++;
            }
            
        }
        return ans;
    }
};