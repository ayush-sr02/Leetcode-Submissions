class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i=0,j=0;
        while(i<nums1.size() and j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                merged.push_back(nums1[i++]);
            }else{
                merged.push_back(nums2[j++]);
            }
        }
        while(i<nums1.size()){
            merged.push_back(nums1[i++]);
        }
        while(j<nums2.size()){
            merged.push_back(nums2[j++]);
        }
        // for(auto i:merged) cout<<i<<" ";
        // cout<<endl;
        double ans;
        int n=merged.size();
        if(n%2==0){
            ans = (double)(merged[n/2]+merged[(n/2)-1])/2;
        }else{
            ans=(double) merged[n/2];
        }
        return ans;
    }
};