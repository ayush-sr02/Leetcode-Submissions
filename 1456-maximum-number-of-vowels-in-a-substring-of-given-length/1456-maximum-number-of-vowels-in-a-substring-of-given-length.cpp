class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        string vowel = "aeiou";
        unordered_set<char> st(vowel.begin(),vowel.end());
        int ans=0;
        int i=0,j=0;
        int cnt=0;
        while(i<n and j<n){
            if(st.count(s[j])) cnt++;
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                ans=max(ans,cnt);
                if(st.count(s[i])) cnt--;
                i++;
                j++;
            }
        }
        return ans;
    }
};