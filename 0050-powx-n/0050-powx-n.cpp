class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long n1=n;
        n1=abs(n1);
        while(n1>0){
            if(n1%2!=0){
                ans*=x;
                n1--;
            }else{
                x*=x;
                n1/=2;
            }
        }
        if(n<0) ans = (double)1.0/ans;
        return ans;
    }
};