class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans=0;
        stack<int> st;
        int score=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(score);
                score=0;
            }else{
                score = st.top()+max(1,2*score);
                st.pop();
            }
         }
        return score;
    }
};