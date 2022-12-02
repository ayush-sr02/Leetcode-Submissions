class Solution {
public:
    //create a frequency array for both the strings and sort them. If they are equal then we can attain one from the other
    
    bool closeStrings(string s, string t) {
        map<char,int> m1,m2;
        for(int i=0;i<s.size();i++) m1[s[i]]++;
        for(int i=0;i<t.size();i++) m2[t[i]]++;
        vector<int> v1,v2;
        for(auto i:m1){
            if(m2.find(i.first)==m2.end()) return false;       // condition for unmatched character.
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