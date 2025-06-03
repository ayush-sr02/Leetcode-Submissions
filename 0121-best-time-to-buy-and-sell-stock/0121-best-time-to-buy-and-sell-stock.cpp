class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),ans=0,cur=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]<cur) cur=prices[i];
            else ans=max(ans,prices[i]-cur);
        }
        return ans;
    }
};