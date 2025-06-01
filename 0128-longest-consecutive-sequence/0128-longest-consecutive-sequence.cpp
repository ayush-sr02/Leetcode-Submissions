class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int ans=0;
        for(auto i:st){
            if(st.find(i-1)==st.end()){
                int num=i,curMax=0;
                while(st.find(num)!=st.end()){
                    curMax+=1;
                    num++;
                }
                ans=max(ans,curMax);
            }
        }
        return ans;
    }
};