class NumArray {
public:
    vector<int> util;
    int sum;
    NumArray(vector<int>& nums) {
        util=nums;
        sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
    }
    
    void update(int index, int val) {
        sum-=util[index];
        util[index]=val;
        sum+=val;
    }
    
    int sumRange(int left, int right) {
        int temp=sum;
        for(int i=0;i<left;i++) temp-=util[i];
        for(int i=right+1;i<util.size();i++) temp-=util[i];
        return temp;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */