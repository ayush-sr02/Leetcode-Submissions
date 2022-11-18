class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if(n<3) return 0;
        int ans=0;
        vector<int> left(n);
        vector<int> right(n);
        int sum=1;
        left[0]=right[n-1]=1;
        for(int i=1;i<n;i++){
            if(arr[i]<=arr[i-1]) sum=1;
            else sum++;
            left[i]=sum;
        }
        sum=1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]<=arr[i+1]) sum=1;
            else sum++;
            right[i]=sum;
        }
        for(int i=1;i<n-1;i++){
            if(left[i]!=1 and right[i]!=1) ans=max(ans,left[i]+right[i+1]);
        }
        return ans;
    }
};