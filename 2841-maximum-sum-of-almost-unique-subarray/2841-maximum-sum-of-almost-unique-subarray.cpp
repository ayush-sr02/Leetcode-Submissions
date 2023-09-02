class Solution {
public:
    #define ll long long
    long long maxSum(vector<int>& nums, int m, int k) {
        if(k==1){
            if(m>1) return 0;
            else return *max_element(begin(nums),end(nums));
        }
        ll sum=0;
        ll ans=0;
        int i=0,j=0,n=nums.size();
        unordered_map<int,int> mp;
        while(j<n){
            sum+=nums[j];
            mp[nums[j]]++;
            if(j-i+1<k) j++;
            else{
                if(mp.size()>=m) ans=max(ans,sum);
                sum-=nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;j++;
            }
        }
        return ans;
    }
};