class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i=0,j=0;
        int n=word1.size(),m=word2.size();
        while(i<word1.size() or j<word2.size()){
            if(i<n) {
                ans+=word1[i];i++;
            }
            if(j<m) {
                ans+=word2[j];j++;
            }
        }
        return ans;
    }
};