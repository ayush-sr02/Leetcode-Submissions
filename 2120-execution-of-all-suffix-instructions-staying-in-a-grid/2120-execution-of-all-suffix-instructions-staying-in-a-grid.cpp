class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& p, string s) {
        vector<int> ans;
        int l=s.length();
        for(int i=0;i<s.length();i++){
            string temp=s.substr(i,l-i);
            int x=p[0],y=p[1];
            int cnt=0;
            for(auto i:temp){
                if(i=='L'){
                    y--;
                    if(y<0) break;
                }
                else if(i=='R'){
                    y++;
                    if(y>=n) break;
                }
                else if(i=='U'){
                    x--;
                    if(x<0) break;
                }
                else{
                    x++;
                    if(x>=n) break;
                }
                cnt++;
            }
                
            ans.push_back(cnt);
        }
        
        return ans;
    }
};