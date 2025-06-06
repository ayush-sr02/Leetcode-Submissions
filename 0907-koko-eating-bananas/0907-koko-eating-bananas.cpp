class Solution {
public:
    long solve(vector<int>&piles,int mid){
        long val = 0;
        for(int i=0;i<piles.size();i++){
            val+=(piles[i]+mid-1)/mid;
        }
        return val;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long low=1, high=*max_element(begin(piles),end(piles));
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            long mx=solve(piles,mid);
            cout<<mid<<" "<<mx<<endl;
            if(mx<=h){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};