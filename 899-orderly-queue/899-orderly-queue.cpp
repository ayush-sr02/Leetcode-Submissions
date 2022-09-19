class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }
        string ans;
        int len=s.length();
        for(int i=0;i<len;i++) ans+='z';
        for(int i=0;i<s.length();i++){
            int l = len-i;
            string temp = s.substr(0,i);
            string temp1 = s.substr(i,l);
            temp1+=temp;;
            ans = min(temp1,ans);
        }
        return ans;
    }
};