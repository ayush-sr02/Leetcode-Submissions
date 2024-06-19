class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int cur=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]-cur>ans) ans = prices[i]-cur;
            cur=min(cur,prices[i]);
        }
        return ans;
    }
};