class Solution {
public:
    
    
    bool closeStrings(string s, string t) {
        if(s.size()!=t.size()) return false;
        sort(begin(s),end(s));
        sort(begin(t),end(t));
        if(s==t) return true;
        map<char,int> m1,m2;
        for(int i=0;i<s.size();i++) m1[s[i]]++;
        for(int i=0;i<s.size();i++) m2[t[i]]++;
        vector<int> v1,v2;
        for(auto i:m1){
            if(m2.find(i.first)==m2.end()) return false;
            v1.push_back(i.second);
        } 
        for(auto i:m2){
            if(m1.find(i.first)==m1.end()) return false;

            v2.push_back(i.second);
        } 
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return v1==v2;
    }
};