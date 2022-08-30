class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                if(!st.empty() and st.top()=='('){
                    st.push(s[i]);
                    ans+=s[i];
                }
                else if(st.empty()){
                    st.push(s[i]);
                }
            }
            else{
                st.pop();
                if(!st.empty()) ans+=s[i];
            }
        }
        return ans;
    }
};