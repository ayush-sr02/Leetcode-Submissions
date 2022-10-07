class Solution {
public:

    int ans=0;
    
    void generate(int i,vector<int> nums,int cur,int mx){
        if(i==nums.size()){
            if(cur==mx){
                ans++;  
            } 
            return;
        }
        generate(i+1,nums,cur,mx);
        generate(i+1,nums,cur|nums[i],mx);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        int cur=0;
        for(int i=0;i<nums.size();i++){
            cur|=nums[i];
        }
        generate(0,nums,0,cur);
        return ans;
    }
};