class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long min=INT_MAX;
        long long n=nums.size();
        long long ans=0;
        vector<long long> num(n,0);
        num[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            num[i] += nums[i]+num[i-1];
        }
        long long sum=num[n-1];
        for(int i=0;i<n;i++){
            if(i==n-1){
                long long temp = sum/n;
                if(temp<min){
                    min=temp;
                    ans=i;
                }
                break;
            }
            long long one = num[i]/(i+1);
            long long two = (sum-num[i])/(n-i-1);
            long long temp=abs(one-two);
            if(temp<min){
                min=temp;
                ans=i;
            }
        }
        return ans;
    }
};