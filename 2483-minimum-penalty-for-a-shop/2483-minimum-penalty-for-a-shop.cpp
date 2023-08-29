class Solution {
public:
    int bestClosingTime(string c) {
        int y=0,n=0;
        for(auto i:c){
            if(i=='Y') y++;
            else n++;
        }
        if(n==0) return c.size();
        if(y==0) return 0;
        int neg=0;
        int ans;
        int mx=1e5+1;
        for(int i=0;i<c.size();i++){
            int dif = y+neg;
            if(dif<mx){
                mx=dif;
                ans=i;
            }
            if(c[i]=='Y') y--;
            else neg++;
        }
        int dif = y+neg;
        if(dif<mx){
            mx=dif;
            ans=c.size();
        }
        return ans;
    }
};