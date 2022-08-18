class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int x=*max_element(arr.begin(),arr.end());
        vector<int> v(x+1,0);
        for(int i=0;i<arr.size();i++) v[arr[i]]++;
        int ans=0;
        int cnt=0;
        int n=arr.size();
        sort(v.rbegin(),v.rend());
        for(auto i:v){
            cnt+=i;
            ans++;
            if(cnt>=n/2) break;
        }
        return ans;
    }
};