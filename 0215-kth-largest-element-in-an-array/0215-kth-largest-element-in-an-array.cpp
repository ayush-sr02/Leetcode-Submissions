class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(begin(nums),end(nums));
        while(!pq.empty() and k-1>0){
            k--;
            pq.pop();
        }
        return pq.top();
    }
};