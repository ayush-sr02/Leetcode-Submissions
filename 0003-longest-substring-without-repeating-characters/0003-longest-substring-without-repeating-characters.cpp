class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        unordered_map<char,int> mp;
        int i=0,j=0;
        int n=s.size();
        int ans=0;
        while(i<n and j<n){
            
            if(mp.find(s[j])==mp.end()){
                mp[s[j]]++;
                ans=max(ans,j-i+1);
                j++;
            }else{
                mp.erase(s[i]);
                i++;
            }
            
            // if(!st.count(s[j])){
            //     st.insert(s[j]);
            //     j++;
            //     int temp=st.size();
            //     ans=max(ans,temp);
            // }else{
            //     st.erase(s[i]);
            //     i++;
            // }
        }
        return ans;
    }
};