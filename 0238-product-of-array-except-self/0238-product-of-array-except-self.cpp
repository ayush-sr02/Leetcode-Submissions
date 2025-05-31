class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(),left=1,right=1;
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            ans[i]=left;
            left*=nums[i];
            cout<<left<<" ";
        }
        cout<<endl;
        for(int i=n-1;i>=0;i--){
            ans[i]*=right;
            right*=nums[i];
            cout<<right<<" ";
        }
        return ans;
    }
};