class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q1,q2;
        int n = senate.size();
        for(int i=0;i<n;i++){
            if(senate[i]=='R') q1.push(i);
            else q2.push(i);
        }
        
        while(!q1.empty() and !q2.empty()){
            int r = q1.front();q1.pop();
            int d = q2.front();q2.pop();
            if(r<d) q1.push(r+n);
            else q2.push(d+n);
        }
        return q2.size()>q1.size()?"Dire":"Radiant";
    }
};