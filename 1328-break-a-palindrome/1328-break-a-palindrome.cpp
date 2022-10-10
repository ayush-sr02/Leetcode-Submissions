class Solution {
public:
    string breakPalindrome(string palin) {
        if(palin.size()==1){
            return "";
        }
        int i;
        for(i=0;i<palin.size();i++){
            if(palin[i]!='a' && i!=palin.size()/2) {
                palin[i] = 'a';
                return palin;
            }
        }
        if(i==palin.size()) palin[i-1]='b';
        return palin;
    }
};