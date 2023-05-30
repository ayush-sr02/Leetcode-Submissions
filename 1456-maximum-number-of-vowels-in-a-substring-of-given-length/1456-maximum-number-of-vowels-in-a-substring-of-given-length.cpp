class Solution {
public:
    int maxVowels(string s, int k) {
        int mx=0;
        string vowel="aeiou";
        set<char> st(vowel.begin(),vowel.end());
        int i=0,j=0;
        int n=s.size();
        int cnt=0;
        
        while(j<n){
            if(st.count(s[j])) cnt++;
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                mx=max(mx,cnt);
                if(st.count(s[i])){
                    cnt--;
                }
                i++;
                j++;
            }
        }
        
        return mx;
    }
};