class Solution {
public:
    
    bool halvesAreAlike(string s) {
        string vowel = "aeiouAEIOU";
        set<char> st(vowel.begin(),vowel.end());
        int l=s.size()/2;
        int n1=0,n2=0;
        for(int i=0;i<s.size()/2;i++){
            if(st.count(s[i])){
                n1++;
            }
            if(st.count(s[l+i])){
                n2++;
            }
        }
        return n1==n2;
    }
};