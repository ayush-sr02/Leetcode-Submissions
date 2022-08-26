class Solution {
public:
    bool reorderedPowerOf2(int nn) {
        unordered_map<string,int> mp;
        int n=1;
        while(n<1e9){
            string s=to_string(n);
            sort(s.begin(),s.end());
            mp[s]++;
            n*=2;
        }
        string temp=to_string(nn);
        sort(temp.begin(),temp.end());
        if(mp.find(temp)!=mp.end()) return true;
        return false;
    }
};