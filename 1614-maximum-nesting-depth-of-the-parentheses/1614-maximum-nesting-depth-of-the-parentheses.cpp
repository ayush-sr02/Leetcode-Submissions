class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        stack<char> st;
        int temp=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
                int x=st.size();
                ans=max(ans,x);
            }
            else if(s[i]==')') st.pop();
        }
        
        return ans;
    }
};