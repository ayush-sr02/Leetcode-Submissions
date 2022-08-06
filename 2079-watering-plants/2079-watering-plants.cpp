class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans=0;
        int t=capacity;
        for(int i=0;i<plants.size();i++){
            if(t-plants[i]>=0){
                ans++;
                t-=plants[i];
            }
            else{
                ans=ans+i+i+1;
                t=capacity-plants[i];
            }
        }
        return ans;
    }
};