class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt1 = __builtin_popcount(num1);
        int cnt2 = __builtin_popcount(num2);
        if(cnt2==cnt1) return num1;
        int j=31;
        int num3=num1;
        vector<int> v(32,0);
        while(num1>0){
            if(num1&1){
                v[j]=1;
            }
            j--;
            num1>>=1;
        }
        if(cnt1>cnt2){
            cnt2=abs(cnt1-cnt2);
            for(int i=31;i>=0;i--){
                if(v[i]){
                    v[i]=0;
                    cnt2--;
                }
                if(cnt2==0) break;
            }
        }
        else{
            cnt1 = abs(cnt1-cnt2);
            for(int i=31;i>=0;i--){
                if(v[i]==0){
                    v[i]=1;
                    cnt1--;
                }
                if(cnt1==0) break;
            }
        }
        int ans=0;
        for(int i=31;i>=0;i--){
            if(v[i]){
                ans+=pow(2,31-i);
            }
        }
        
        return ans;
    }
};