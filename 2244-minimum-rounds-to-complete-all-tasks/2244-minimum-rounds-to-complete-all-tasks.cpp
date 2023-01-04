class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        int ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        for(auto it:mp){
            int x=it.second;
            if(x==1) return -1;
            else if(x==2){
                ans+=1;
            } 
            else if(x%3==0){
                ans+=x/3;
            }
            else{
                ans+=(x/3)+1;
            }     
        }
        return ans;
    }
};