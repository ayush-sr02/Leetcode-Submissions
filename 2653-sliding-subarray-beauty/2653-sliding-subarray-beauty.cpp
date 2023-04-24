#define pi pair<int,int> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        ordered_set st;
        int i=0,j=0;
        vector<int> ans;
        int n = nums.size();
        while(i<n and j<n){
            if(nums[j]<0) st.insert({nums[j],j});
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){   // window size equal to target
                if(st.size()<x){    // less than req no of negatives in the window
                    ans.push_back(0);
                }else{
                    auto z = *st.find_by_order(x-1);
                    ans.push_back(z.first);
                }
                st.erase({nums[i],i});
                i++;j++;
            }
        }
        return ans;
    }
};