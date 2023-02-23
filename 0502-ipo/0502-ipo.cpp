class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v;
        for(int i=0;i<profits.size();i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(begin(v),end(v));
        // for(auto i:v){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        priority_queue<int>pq;
        int i=0;
        while(k--){
            while(i<v.size() and w>=v[i].first){
               pq.push(v[i].second);
               i++; 
            }
            if(pq.empty())break;
            w+=pq.top();
            pq.pop();
        }
       return w;
    }
};  