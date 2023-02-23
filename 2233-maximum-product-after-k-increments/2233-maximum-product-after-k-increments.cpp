class Solution {
public:
    #define ll long long
    int maximumProduct(vector<int>& nums, int k) {
        int mod=1e9+7;
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());
        while(k--){
            int x=pq.top();
            pq.pop();
            x++;
            pq.push(x);
        }
        ll ans=1;
        while(!pq.empty()){
            ll x=1ll*pq.top();
            pq.pop();
            ans=(ans*x)%mod;
        }
        return (int)ans;
    }
};