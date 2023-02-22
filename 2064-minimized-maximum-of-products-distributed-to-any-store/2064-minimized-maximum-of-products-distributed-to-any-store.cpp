class Solution {
public:
    
    int check(vector<int>&q,int k){
        int cnt=0;
        for(int i=0;i<q.size();i++){
            int cur = q[i]/k;
            if(q[i]%k!=0) cur++;
            cnt+=cur;
        }
        return cnt;
    }
    
    int minimizedMaximum(int n, vector<int>& q) {
        sort(begin(q),end(q));
        int ans=INT_MAX;
        int low=1;
        int high=*max_element(q.begin(),q.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            int x=check(q,mid);
            if(x<=n){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};