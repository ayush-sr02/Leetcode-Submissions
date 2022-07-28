class Solution {
public:
    int totalMoney(int n) {
        int sum=0;
        int x=1,y=1;
        int t=0;
        while(t!=n){
            if(t!=0 and t%7==0){
                x++;
                sum+=x;
                y=x+1;
            }else{
                sum+=y;y++;
            }
            t++;
        }
        return sum;
    }
};