class Solution {
public:
    int minOperations(int n) {
        int count =0;
        while(n > 0){
          if((n & 1) == 1){
              count++;
              n /= 2;
              if((n & 1) == 1)
               n++;
          }
          else{
              n /= 2;
          }
      }
      return count;
    }
};