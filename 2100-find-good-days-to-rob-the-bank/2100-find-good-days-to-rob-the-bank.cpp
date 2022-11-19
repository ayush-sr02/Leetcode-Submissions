class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& s, int time) {
        vector<int> ans;
        int n = s.size();
        vector<int> left(n),right(n);
        int sum=1;
        left[0]=right[n-1]=1;
        for(int i=1;i<n;i++){
            if(s[i]>s[i-1]) sum=1;
            else sum++;
            left[i]=sum;
        }
        sum=1;
        for(int i=n-2;i>=0;i--){
            if(s[i]>s[i+1]) sum=1;
            else sum++;
            right[i]=sum;
        }
        
        // for(auto i:left) cout<<i<<" ";
        // cout<<endl;
        // for(auto i:right) cout<<i<<" ";
        for(int i=time;i<n-time;i++){
            if(left[i]>time and right[i]>time) ans.push_back(i);
        }
        return ans;
    }
};