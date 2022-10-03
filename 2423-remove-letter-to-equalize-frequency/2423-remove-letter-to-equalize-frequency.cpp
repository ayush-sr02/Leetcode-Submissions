class Solution {
public:
    bool equalFrequency(string word) {
        int len = word.size();
        for(int i=0;i<len;i++){
            string temp = word.substr(0,i);
            string temp1 = word.substr(i+1,len-i);
            temp+=temp1;
            map<char,int> mp;
            for(auto x:temp){
                mp[x]++;
            }
            set<int> s;
            for(auto x:mp) s.insert(x.second);
            if(s.size()==1) return true;
        }
        return false;
    }
};