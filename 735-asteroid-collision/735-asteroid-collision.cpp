class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> ans;
        stack<int> s;
        for(int i=0;i<a.size();i++){
            if(s.empty() or a[i]>0){
                s.push(a[i]);
                continue;
            }
            while(!s.empty() and s.top()>0 and s.top()<abs(a[i])){
                s.pop();
            }
            if(!s.empty() and s.top()==abs(a[i])){
                s.pop();
            }
            else if(s.empty() or s.top()<0) s.push(a[i]); 
            
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};