class Solution {
public:
    bool canTransform(string start, string end) {
        int n=start.size();
        stack<pair<char,int>> s1,s2;
        for(int i=0;i<start.size();i++){
            if(start[i]=='R') s1.push({'R',i});
            if(start[i]=='L') s1.push({'L',i});
            if(end[i]=='R') s2.push({'R',i});
            if(end[i]=='L') s2.push({'L',i});

        }
        if(s1.size()!=s2.size()) return false;
        // cout<<s1.top().first<<" "<<s2.top().first;
        
        while(!s1.empty() and !s2.empty()){
            if(s1.top().first!=s2.top().first) return false;
            if(s1.top().first=='L'){
                if(s1.top().second<s2.top().second) return false;
            }else{
                if(s1.top().second>s2.top().second) return false;
            }
            s1.pop();
            s2.pop();
        }
        return true;
    }
};