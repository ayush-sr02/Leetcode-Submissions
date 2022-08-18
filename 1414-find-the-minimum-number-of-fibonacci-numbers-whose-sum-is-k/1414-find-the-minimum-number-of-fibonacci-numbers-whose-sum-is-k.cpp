class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib;
        fib.push_back(1);
        fib.push_back(1);
        int ans=0;
        for(int i=2;i<100;i++){
            fib.push_back(fib[i-1]+fib[i-2]);
            if(fib[i]>1e9) break;
        }
        while(true){
            for(int i=0;i<fib.size();i++){
                if(fib[i]<=k and fib[i+1]>k){
                    ans++;
                    k-=fib[i];
                }
            }
            if(k<=0) break;
        }
        
        return ans;
    }
};