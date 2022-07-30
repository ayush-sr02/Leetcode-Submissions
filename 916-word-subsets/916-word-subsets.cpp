class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> v2(26,0);
        for(auto i:words2){
            vector<int> v1(26,0);
            for(auto j:i) v1[j-'a']++;
            for(int x=0;x<26;x++){
                v2[x] = max(v2[x],v1[x]);
            }
        }
        
        for(auto i:words1){
            vector<int> temp(26,0);
            bool flag=true;
            for(auto j:i) temp[j-'a']++;
            for(int x=0;x<26;x++){
                if(temp[x]<v2[x]){
                    flag=false;
                    break;
                }
            }
            if(flag) ans.push_back(i);
        }
        return ans;
    }
};