class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<int,int>> st;
        unordered_set<int> v;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push({s[i],i});
            }else if(s[i]==')'){
                if(!st.empty()) st.pop();
                else{
                    v.insert(i);
                }
            }
        }
        while(!st.empty()){
            v.insert(st.top().second);
            st.pop();
        }
        for(int i=0;i<s.size();i++){
            if(v.count(i)==0) ans+=s[i];
        }
        return ans;
    }
};