class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n,0),right(n,0);
        int ans=0;
        int l=0,r=0;
        for(int i=0;i<n;i++){
            l=max(l,height[i]);
            left[i]=l;
        }
        for(int i=n-1;i>=0;i--){
            r=max(r,height[i]);
            right[i]=r;
        }
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
    }
};