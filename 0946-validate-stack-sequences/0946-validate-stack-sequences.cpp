class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n=pushed.size(),i=0,j=0;;
        while(i<n and j<n){
            st.push(pushed[i]);
            while(!st.empty() and j<n){
                if(st.top()==popped[j]){
                    st.pop();
                    j++;
                }else break;
            }
            i++;
        }
        while(j<n){
            if(!st.empty() and st.top()==popped[j]){
                st.pop();j++;
            }else break;
        }
        
        return st.empty();
    }
};