class Solution {
public:
    
    int solve(vector<int> &w,int k,int days){
        int res=0;
        int curWt=0;
        int n=w.size();
        for(int i=0;i<n;i++){
            if(curWt+w[i]<=k) curWt+=w[i];
            else{
                res++;
                curWt=w[i];
                if(res>days) return INT_MAX;
            }
        }
        return res;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int ans=INT_MAX;
        int mx=*max_element(weights.begin(),weights.end());
        int sum=accumulate(weights.begin(),weights.end(),0);
        int low=mx,high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            int x=solve(weights,mid,days);
            if(x<days){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        
        return ans;
    }
};