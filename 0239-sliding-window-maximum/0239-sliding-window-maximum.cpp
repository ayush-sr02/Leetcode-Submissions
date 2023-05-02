class Solution {
public:
    
    vector<int> segment;
    
    void buildTree(int start,int end,vector<int>&nums,int idx){
        if(start>end) return;
        if(start==end){
            segment[idx] = nums[start];
            return;
        }
        int mid = start+(end-start)/2;
        buildTree(start,mid,nums,2*idx);
        buildTree(mid+1,end,nums,2*idx+1);
        segment[idx] = max(segment[2*idx],segment[2*idx+1]);
    }
    
    int query(int start,int end,int left,int right,int idx){
        if(left>end or right<start) return INT_MIN;
        if(start>=left and end<=right) return segment[idx];
        int mid = start+(end-start)/2;
        int l = query(start,mid,left,right,2*idx);
        int r = query(mid+1,end,left,right,2*idx+1);
        return max(l,r);
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        segment.resize(4*n,INT_MIN);
        buildTree(0,n-1,nums,1);
        // for(auto i:segment) cout<<i<<" ";
        vector<int> ans(n-k+1);
        for(int i=0;i<n-k+1;i++){
            int temp = query(0,n-1,i,i+k-1,1);
            ans[i] = temp;
        }
        return ans;
    }
};