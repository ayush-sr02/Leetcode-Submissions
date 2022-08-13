class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        map<string,int> mp;
        for(auto i:words) mp[i]++;
        int len=words[0].size();
        int req = words[0].size()*words.size();
        for(int i=0;i<s.length()-req+1;i++){
            bool flag=true;
            map<string,int> m;
            string temp=s.substr(i,req);
            for(int j=i;j<req+i;j+=len){
                string x=s.substr(j,len);
                if(mp.find(x)==mp.end()){
                    flag=false;
                    break;
                }else{
                    m[x]++;
                }
            }
            if(!flag) continue;
            if(m==mp){
                ans.push_back(i);
                // i+=len-1;
            }
        }        
        return ans;
    }
};