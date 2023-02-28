class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> st;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            string odd="",even="";
            for(int j=0;j<s.size();j++){
                if(j%2==0) even+=s[j];
                else odd+=s[j];
            }
            sort(begin(odd),end(odd));
            sort(begin(even),end(even));
            odd+=even;
            st.insert(odd);
        }
        return st.size();
    }
};