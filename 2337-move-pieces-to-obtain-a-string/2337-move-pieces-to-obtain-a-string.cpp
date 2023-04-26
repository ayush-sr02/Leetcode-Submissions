class Solution {
public:
    bool canChange(string start, string target) {
        stack<pair<char,int>> s1,s2;
        for(int i=0;i<start.size();i++){
            if(start[i]=='L'){
                s1.push({'L',i});
            }
            if(start[i]=='R'){
                s1.push({'R',i});
            }
            if(target[i]=='L'){
                s2.push({'L',i});
            }
            if(target[i]=='R'){
                s2.push({'R',i});
            }
        }
        if(s1.size()!=s2.size()) return false;
        while(!s1.empty() and !s2.empty()){
            if(s1.top().first!=s2.top().first) return false;
            if(s1.top().first=='L'){
                if(s1.top().second<s2.top().second) return false;//case when L in target has to move right
            }
            if(s1.top().first=='R'){
                if(s1.top().second>s2.top().second) return false;
            }
            s1.pop();
            s2.pop();
        }
        return true;
    }
};