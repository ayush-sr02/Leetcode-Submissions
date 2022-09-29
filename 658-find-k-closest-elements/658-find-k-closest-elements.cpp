class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        for(int i=0;i<arr.size();i++){
            int dif = abs(x-arr[i]);
            pq.push(make_pair(dif,arr[i]));
        }
        while(!pq.empty() and k--){
            auto top=pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};