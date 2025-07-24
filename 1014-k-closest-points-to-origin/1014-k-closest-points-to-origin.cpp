class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
        for(auto i:points){
            int dist = (i[0]*i[0])+(i[1]*i[1]);
            pq.push({dist,{i[0],i[1]}});
        }
        while(k--){
            vector<int> cur = pq.top().second;
            pq.pop();
            ans.push_back(cur);
        }
        return ans;
    }
};