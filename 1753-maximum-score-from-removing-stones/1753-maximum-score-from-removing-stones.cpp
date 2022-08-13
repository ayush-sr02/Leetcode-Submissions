class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int ans=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        while(pq.size()>2){
            int x=pq.top();pq.pop();
            int y=pq.top();pq.pop();
            int z=pq.top();pq.pop();
            x--;
            z--;
            ans++;
            if(x>0) pq.push(x);
            if(z>0) pq.push(z);
            pq.push(y);
        }
        if(pq.size()==2) ans+=pq.top();
        return ans;
    }
};