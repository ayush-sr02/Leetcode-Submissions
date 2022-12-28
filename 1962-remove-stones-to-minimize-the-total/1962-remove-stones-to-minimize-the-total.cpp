class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int ans=0;
        priority_queue<int> pq(piles.begin(),piles.end());
        while(!pq.empty()){
            if(!k) break;
            int top = pq.top();pq.pop();
            if(top%2==0) top/=2;
            else top = (top/2)+1;
            pq.push(top);
            k--;
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};