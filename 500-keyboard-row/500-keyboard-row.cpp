class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s1="qwertyuiopQWERTYUIOP",s2="asdfghjklASDFGHJKL",s3="zxcvbnmZXCVBNM";
        map<char,int> mp;
        vector<string> ans;
        for(auto i:s1) mp[i]=1;
        for(auto i:s2) mp[i]=2;
        for(auto i:s3) mp[i]=3;

        for(auto i:words){
            bool flag=true;
            for(int j=1;j<i.size();j++){
                if(mp[i[j-1]]!=mp[i[j]]){
                    flag=false;
                    break;
                }
            }
            if(flag) ans.push_back(i);
        }
        
        return ans;
    }
};