class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v=arr;
        sort(begin(arr),end(arr));
        vector<int> ans;
        int rank=1;
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=rank;
            rank++;
            while(i<arr.size()-1){
                if(arr[i+1]==arr[i]) i++;
                else break;
            }
        }
        for(int i=0;i<v.size();i++){
            ans.push_back(mp[v[i]]);
        }
        return ans;
    }
};