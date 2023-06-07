class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(c!=0 or b!=0 or a!=0){
            int cnt=0;
            if(a&1) cnt++;
            if(b&1) cnt++;
            if(c&1){
                if(cnt==0) ans++;
            }else{
                if(cnt==1) ans++;
                else if(cnt==2) ans+=2;
            }
            a>>=1,b>>=1,c>>=1;
        }
        
        return ans;
    }
};