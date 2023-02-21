class Solution {
public:
    
    string fn(string s){
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') s[i]='1';
            else s[i]='0';
        }
        reverse(begin(s),end(s));
        return s;
    }
    
    char findKthBit(int n, int k) {
        string prev;
        string cur="0";
        for(int i=1;i<=n;i++){
            prev=cur;
            cur = prev+"1"+fn(prev);
        }
        return prev[k-1];
    }
};