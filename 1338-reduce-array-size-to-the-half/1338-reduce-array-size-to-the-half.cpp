class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        map<int,int> mp;
        priority_queue<int> pq;
        for(auto i:arr) mp[i]++;
        for(auto i:mp) pq.push(i.second);
        int cnt=0;
        while(!pq.empty()){
            cnt+=pq.top();
            ans++;
            if(cnt>=n/2) break;
            pq.pop();
        }
        return ans;
    }
};