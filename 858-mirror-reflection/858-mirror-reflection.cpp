class Solution {
public:
    int mirrorReflection(int p, int q) {
        while(p%2==0 and q%2==0){
            p/=2;
            q/=2;
        }
        int ans = ((p%2)==0 && (q%2)!=0)?2:((p%2)!=0 && (q%2)!=0)?1:0;
        return ans;
    }
};