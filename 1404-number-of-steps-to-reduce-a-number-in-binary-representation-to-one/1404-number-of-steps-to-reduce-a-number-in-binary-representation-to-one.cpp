class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        
        while(s.size()!=1){
            if(s[s.size()-1]=='0'){
                s.pop_back();
            }else{
                int i=s.size()-1;
                bool flag=true;
                
                while(i>=0){
                    if(!flag) break;
                    if(s[i]=='1'){
                        s[i]='0';
                    }else{
                        s[i]='1';
                        flag=false;
                    }
                    i--;
                }
                if(i<0){
                    s='1'+s;
                }
            }
            ans++;
        }
        
        return ans;
    }
};