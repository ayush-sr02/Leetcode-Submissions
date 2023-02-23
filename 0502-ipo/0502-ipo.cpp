class Solution {
public:

/* create list of pair and sort it according to increasing capital, then while current capital    is greater than that of the ith project push it's profit in the max heap. Then pick the    project with max profit and add it to your capital. */
    
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        vector<pair<int,int>> v;
        for(int i=0;i<p.size();i++){
            v.push_back({c[i],p[i]});
        }
        sort(begin(v),end(v));
        priority_queue<int> pq;
        int i=0;
        while(k--){
            while(i<v.size() and w>=v[i].first){
                pq.push(v[i].second);
                i++;
            }
            if(pq.empty()) continue;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};