class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(auto i:s) mp[i]++;
        priority_queue<pair<int,char>> pq;
        string ans="";
        for(auto i:mp){
            pq.push(make_pair(i.second,i.first));
        }
        while(!pq.empty()){
            int freq=pq.top().first;
            char ch=pq.top().second;
            while(freq--){
                ans+=ch;
            }
            pq.pop();
        }
        return ans;
    }
};