class Solution {
public:
    vector<string> ans;
    set<string> st;
    void solve(string s,string temp,int i){
        if(i==s.length()){
            st.insert(temp);
            return;
        }
        temp+=toupper(s[i]);
        solve(s,temp,i+1);
        temp.pop_back();
        temp+=tolower(s[i]);
        solve(s,temp,i+1);
        temp.pop_back();
    }
    
    vector<string> letterCasePermutation(string s) {
        string temp="";
        solve(s,temp,0);
        for(auto i:st) ans.push_back(i);
        return ans;
    }
};