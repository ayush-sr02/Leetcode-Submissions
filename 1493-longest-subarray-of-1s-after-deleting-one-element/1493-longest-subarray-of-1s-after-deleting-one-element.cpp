class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int ans=0;
        vector<int> pre;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(sum==0) pre.push_back(0);
                else{
                    pre.push_back(sum);
                    sum=0;
                }
            }
            else sum++;
        }
        pre.push_back(sum);
        // for(auto i:pre) cout<<i<<" ";
        // cout<<"\n";
        if(pre.size()==1){
            if(pre[0]==0) return 0;
            else return pre[0]-1;
        }
        for(int i=0;i<pre.size()-1;i++){
            ans = max(ans,pre[i]+pre[i+1]);
        }
        return ans;
        
    }
};