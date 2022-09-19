class Solution {
public:
    vector<int> ans;
    
    void solve(int num,int n,int k,int x){
        if(x==0){
            ans.push_back(num);
            return;
        }
        int temp=num%10;
        for(int i=0;i<=9;i++){
            if(abs(i-temp)==k){
                solve(num*10+i,n,k,x-1);
            }
        }
    }
    
    
    vector<int> numsSameConsecDiff(int n, int k) {
        int x=n-1;
        for(int i=1;i<=9;i++){
            solve(i,n,k,x);
        }
        return ans;
    }
};