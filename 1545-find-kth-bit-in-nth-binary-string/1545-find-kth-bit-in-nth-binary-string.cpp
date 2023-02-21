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
        vector<string> v(n+1);
        v[0]="0";
        for(int i=1;i<=n;i++){
            string s = v[i-1]+"1"+fn(v[i-1]);
            v[i]=s;
        }
        string ans=v[n];
        return ans[k-1];
    }
};