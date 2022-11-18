class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if(n<3) return 0;
        bool flag=false;
        for(int i=0;i<n-2;i++){
            if(arr[i]<arr[i+1] and arr[i+1]>arr[i+2]) flag=true;
        }
        if(!flag) return 0;
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
        int sumLeft = accumulate(left.begin(),left.end(),0);
        int sumRight = accumulate(right.begin(),right.end(),0);
        if(sumLeft==n or sumRight==n) return 0;
        for(auto i:left) cout<<i<<" ";
        cout<<"\n";
        for(auto i:right) cout<<i<<" ";
        for(int i=1;i<n-1;i++){
            // ans=max(ans,left[i]+right[i+1]);
            if(left[i]!=1 and right[i]!=1) ans=max(ans,left[i]+right[i+1]);
        }
        return ans;
    }
};