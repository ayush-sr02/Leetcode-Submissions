class Solution {
public:
    //use two pointer and move the pointer with smaller height
    
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int ans=0;
        while(l<r){
            int curWidth = r-l;
            int curHeight = min(height[l],height[r]);
            ans=max(ans,curWidth*curHeight);
            if(height[l]<height[r]){
                l++;
            }else if(height[l]>height[r]){
                r--;
            }else{
                l++;r--;
            }
        }
        return ans;
    }
};