class Solution {
public:
    int countCollisions(string d) {
        int ans=0;
        stack<char> st;
        for(int i=0;i<d.size();i++){
            if(d[i]=='R') st.push(d[i]);
            else if(d[i]=='S'){
                while(!st.empty() and st.top()=='R'){
                    st.pop();
                    ans++;
                }
                st.push('S');
            }
            else{
                if(!st.empty() and st.top()=='R'){
                    ans+=2;
                    st.pop();
                    while(!st.empty() and st.top()=='R'){
                        st.pop();
                        ans++;
                    }
                    st.push('S');
                }
                else if(!st.empty() and st.top()=='S'){
                    ans++;
                    st.push('S');
                }
                else st.push('L');
            }
        }
        return ans;
    }
};