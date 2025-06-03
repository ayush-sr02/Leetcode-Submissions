class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, cur=prices[0], n=prices.size();
        for(int i=1;i<n;i++){
            if(prices[i]<cur) cur=prices[i];
            else{
                ans+=(prices[i]-cur);
                cur=prices[i];
            }
        }
        return ans;
    }
};