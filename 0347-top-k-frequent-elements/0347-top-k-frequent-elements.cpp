class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // if(k==nums.size()-1) return nums;
        unordered_map<int,int> mp;
        vector<int> ans(k);
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> :: iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            pq.push(make_pair(it->second,it->first));
        }
        for(int i=0;i<k;i++){
            ans[i]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};