class Solution {
public:
    
    int solve(vector<int> &nums,int mid){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int temp = ceil(1.0*nums[i]/mid);
            sum+=temp;
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(begin(nums),end(nums));
        int ans=1e9;
        while(low<=high){
            int mid=low+(high-low)/2;
            int x=solve(nums,mid);
            if(x<=threshold){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        cout<<endl;
        return ans;
    }
};