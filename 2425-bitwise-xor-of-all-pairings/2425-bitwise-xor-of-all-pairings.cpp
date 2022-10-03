class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size(),l2=nums2.size();
        int ans=0;
        if(l2%2==0 and l1%2==0) return 0;
        if(l2%2==1){
            for(auto i:nums1) ans^=i;
        }
        if(l1%2==1) {
            for(auto i:nums2) ans^=i;
        }
        return ans;
    }
};