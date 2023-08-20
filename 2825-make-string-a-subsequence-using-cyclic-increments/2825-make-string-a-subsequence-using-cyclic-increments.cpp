class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        int i=0,j=0;
        while(i<n and j<m){
            if(s[i]==t[j] or s[i]+1==t[j]){
                i++;j++;
            }else if(s[i]=='z' and t[j]=='a'){
                i++;j++;
            }else i++;
        }
        return j==m;
    }
};