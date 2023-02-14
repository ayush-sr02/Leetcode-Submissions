class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int carry=0;
        int n=a.size(),m=b.size();
        int i=n-1,j=m-1;
        while(i>=0 and j>=0){
            char x=a[i],y=b[j];
            if(x=='1' and y=='1'){
                if(carry==1){
                    ans+='1';
                }else{
                    ans+='0';
                    carry=1;
                }
            }
            else if(x=='0' and y=='0'){
                if(carry){
                    ans+='1';
                    carry=0;
                }else{
                    ans+='0';
                }
            }
            else{
                if(carry){
                    carry=1;
                    ans+='0';
                }else{
                    carry=0;
                    ans+='1';
                }
            }
            i--;j--;
        }
        while(i>=0){
            if(a[i]=='1'){
                if(carry){
                    ans+='0';
                }else{
                    ans+='1';
                }
            }else{
                if(carry){
                    ans+='1';
                    carry=0;
                } 
                else ans+='0';
            }
            i--;
        }
        while(j>=0){
            if(b[j]=='1'){
                if(carry){
                    ans+='0';
                }else{
                    ans+='1';
                }
            }else{
                if(carry){
                    ans+='1';
                    carry=0;
                } 
                else ans+='0';
            }
            j--;
        }
        if(carry) ans+='1';
        reverse(begin(ans),end(ans));
        return ans;
    }
};