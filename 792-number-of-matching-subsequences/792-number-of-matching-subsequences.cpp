class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        unordered_map<string,int> mp;
        for(auto i:words){
            if(mp.find(i)!=mp.end()){
                if(mp[i]==1){
                    ans++;
                }
                continue;
            }
            int j=0,k=0;
            string temp=i;
            while(j<s.size() && k<temp.size()){
                if(s[j]==temp[k]) {
                    j++;k++;
                    if(k==temp.size()) break;
                } else j++;
            }
            if(k==temp.size()){
                mp[temp]++;
                ans++;
            }
            else{
                mp[temp]=-1;
            }
        }
        return ans;
    }
};