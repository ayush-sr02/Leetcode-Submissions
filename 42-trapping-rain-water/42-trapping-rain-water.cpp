class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> left(size);
        vector<int> right(size);
        int maxx = INT_MIN;
        // left[0] = height[0];
        for(int i=0;i<size;i++){
            maxx = max(maxx,height[i]);
            left[i] = maxx;
        }
        int minn = INT_MIN;
        for(int i=size-1;i>=0;i--){
            minn = max(minn,height[i]);
            right[i] = minn;
        }
        int ans=0;
        for(int i=0;i<size;i++){
            ans= ans+min(left[i],right[i])-height[i];
        }
        return ans;
    }
};