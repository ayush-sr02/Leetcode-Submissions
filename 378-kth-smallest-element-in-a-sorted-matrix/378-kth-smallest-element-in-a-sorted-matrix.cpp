class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        priority_queue<int,vector<int>, greater<int> > pq;
        int n=m.size();
        for(auto i:m){
            for(auto j:i){
                pq.push(j);
            }
        }
        while(!pq.empty() && k-1!=0){
            int q=pq.top();
            pq.pop();
            k--;
        }
        return pq.top();
    }
};