class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        map<string,string> mp;
        for(auto i:k){
            mp[i[0]]=i[1];
        }
        string ans;
        bool flag=true;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                flag=false;
            }
            else if(s[i]==')'){
                if(mp.count(temp)){
                    ans+=mp[temp];
                }else{
                    ans+='?';
                }
                temp="";
                flag=true;
            }
            else if(flag) ans+=s[i];
            else temp+=s[i];
        }
        return ans;
    }
};