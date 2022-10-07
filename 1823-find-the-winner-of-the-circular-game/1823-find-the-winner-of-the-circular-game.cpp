class Solution {
public:
    
    int josephus(int n,int k){
        if(n==1) return 0;
        int temp=josephus(n-1,k);
        int temp1=(temp+k)%n;
        return temp1;
    }
    
    int findTheWinner(int n, int k) {
        if(k>n) k%=n;
        return josephus(n,k)+1;
    }
};