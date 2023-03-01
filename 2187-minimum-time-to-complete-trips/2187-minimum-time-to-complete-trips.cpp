class Solution {
public:
    #define ll long long
    
    ll solve(ll mid,vector<int>&time){
        ll cnt=0;
        for(int i=0;i<time.size();i++){
            ll temp = 1ll*(mid/time[i]);
            cnt+=temp;
        }
        return cnt;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll ans=LONG_MAX;
        int n=time.size();
        ll low=0;
        ll high=1e14;
        while(low<=high){
            ll mid=low+(high-low)/2;
            ll x=solve(mid,time);
            if(x>=totalTrips){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};