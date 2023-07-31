class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=0;
        int ans=0;
        unordered_map<int,int> mp;
        
        while(j<n){
            mp[nums[j]]++;
            while(i<=j and mp.size()==s.size()){
                ans+=(n-j);
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};