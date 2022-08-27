class Solution {
public:
    vector<string> store;
    void backTrack(string s,int i,int size,map<string,int> mp,bool &flag){
        if(i==size){
            store.push_back(s);
            if(mp.find(s)==mp.end()) flag=true;
            return;
        }
        if(flag) return;
        s+='0';
        if(flag) return;
        backTrack(s,i+1,size,mp,flag);
        if(flag) return;
        s.pop_back();
        s+='1';
        backTrack(s,i+1,size,mp,flag);
        if(flag) return;
        s.pop_back();
        if(flag) return;

    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        map<string,int> mp;
        for(auto i:nums) mp[i]++;
        int n=nums[0].size();
        string s="";
        bool flag=false;
        backTrack(s,0,n,mp,flag);
        for(auto i:store) if(mp.find(i)==mp.end()) return i;
        return "";
    }
};