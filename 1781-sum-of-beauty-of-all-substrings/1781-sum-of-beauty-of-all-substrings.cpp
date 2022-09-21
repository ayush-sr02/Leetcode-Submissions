class Solution {
public:
    int find(vector<int> pre){
        int mx=INT_MIN,mn=INT_MAX;
        for(auto i:pre){
            if(i==0) continue;
            if(i>mx){
                mx=i;
            }
            if(i<mn){
                mn=i;
            }
        }
        return mx-mn;
    }
    
    int beautySum(string s) {
        vector<int> pre(26,0);
        vector<int> temp=pre;
        int sum=0;
        for(int i=0;i<s.length();i++){
            int x=s[i]-'a';
            pre[x]++;
        }
        for(int i=0;i<s.size();i++){
            pre=temp;
            for(int j=i;j<s.size();j++){
                pre[s[j]-'a']++;
                sum+=find(pre);
            }
        }
        
        return sum;
    }
};