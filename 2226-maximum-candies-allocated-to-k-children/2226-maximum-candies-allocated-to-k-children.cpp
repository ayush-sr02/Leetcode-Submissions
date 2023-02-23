class Solution {
public:
    #define ll long long
    ll check(vector<int>&c,int mid){
        ll cnt=0;
        for(int i=0;i<c.size();i++){
            cnt+=(c[i]/mid);
        }
        return cnt;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        sort(begin(candies),end(candies));
        int ans=0;
        int low=1,high=candies[candies.size()-1];
        while(low<=high){
            int mid=low+(high-low)/2;
            ll x=check(candies,mid);
            if(x>=k){
                ans=max(ans,mid);
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};