class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1) return true;
        if(n<3) return false;
        long long x=3;
        while(x<=n){
            if(x==n) return true;
            x*=3;
        }
        return false;
    }
};