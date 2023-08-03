class Solution {
public:
    vector<string> ans;
    
    void solve(string& digits,int i,vector<string>& v,string cur){
        if(i==digits.size()){
            if(cur!="") ans.push_back(cur);
            return;
        }
        int x = digits[i]-'0';
        for(int j=0;j<v[x].size();j++){
            cur+=v[x][j];
            solve(digits,i+1,v,cur);
            cur.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,0,v,"");
        return ans;
    }
};