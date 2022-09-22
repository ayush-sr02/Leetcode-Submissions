class Solution {
public:
    int clumsy(int n) {
        int ans=0;
        stack<int> s;
        bool flag=true;
        while(n>0){
            int t=3;
            int temp=n;
            n--;
            while(n>0 and t>0){
                switch(t){
                    case 3:
                        temp*=n;
                        n--;
                        break;
                    case 2:
                        temp/=n;
                        n--;
                        break;
                    case 1:
                        if(!flag){
                            temp = (-1*temp)+n;
                        }
                        else temp+=n;
                        n--;
                        break;
                    default:
                        break;
                }
                t--;
            }
            if(temp>0 and !flag) temp*=-1;
            flag=false;
            
            s.push(temp);
        }
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};