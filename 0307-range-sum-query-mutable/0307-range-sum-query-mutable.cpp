class NumArray {
public:
    
    vector<int> segment;
    vector<int> num;
    int n;
    void buildTree(int start,int end,int idx){
        if(start>end) return;
        if(start==end){
            segment[idx] = num[start];
            return;
        }
        int mid = start+(end-start)/2;
        buildTree(start,mid,2*idx);
        buildTree(mid+1,end,2*idx+1);
        segment[idx] = segment[2*idx]+segment[2*idx+1];
    }
    
    int query(int start,int end,int left,int right,int idx){
        if(left>end or right<start) return 0;
        if(start>=left and end<=right) return segment[idx];
        int mid = start+(end-start)/2;
        int l = query(start,mid,left,right,2*idx);
        int r = query(mid+1,end,left,right,2*idx+1);
        return (l+r);
    }
    
    void Update(int start,int end,int index,int val,int idx){
        if(start==end){
            segment[idx]=val;
            num[start]=val;
            return;
        }else{
            int mid = start+(end-start)/2;
            if(index>=start and index<=mid){
                Update(start,mid,index,val,2*idx);
            }
            else{
                Update(mid+1,end,index,val,2*idx+1);
            }
            segment[idx] = segment[2*idx]+segment[2*idx+1];
        }
    }
    
    NumArray(vector<int>& nums) {
        num=nums;
        n = nums.size();
        segment.resize(4*n,0);
        buildTree(0,n-1,1);
    }
    
    void update(int index, int val) {
        Update(0,n-1,index,val,1);
    }
    
    int sumRange(int left, int right) {
        return query(0,n-1,left,right,1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */