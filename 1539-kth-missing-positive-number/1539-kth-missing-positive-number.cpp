class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> v(2001,0);
        for(int i=0;i<arr.size();i++){
            v[arr[i]]=1;
        }
        int x=0;
        for(int i=1;i<v.size();i++){
            if(v[i]==0){
                x++;
                if(x==k) return i;
            }
        }
        return -1;
    }
};