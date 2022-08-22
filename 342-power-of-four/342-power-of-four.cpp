class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1) return true;
        if(n<0) return false;
        int x=__builtin_popcount(n);
        if(x!=1) return false;
        long long temp=log2(n & -n) + 1;
        if(temp%2!=1) return false;
        cout<<x<<" "<<temp;
        return true;
    }
};