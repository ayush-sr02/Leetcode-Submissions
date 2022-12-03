class Solution {
public:
    int minOperations(int n) {
        int ans=0;
        int target=0;
        for(int i=0;i<n;i++){
            target+=(2*i+1);
        }
        target/=n;
        for(int i=0;i<n;i++){
            if(2*i+1>=target) break;
            ans+=(target-(2*i+1));
        }
        return ans;
    }
};