class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int x) {
        
        int count=0;
        int n = f.size();
        for(int i=0;i<n;i++){
              if(f[i]==0){
                  int prev = (i==0 || f[i-1]==0)?0:1;
                  int next = (i==n-1 || f[i+1]==0)?0:1;
                  if(prev==0 && next==0){
                      count++;
                      f[i]=1;
                  } 
              }
        }
        return count>=x;
    }
};