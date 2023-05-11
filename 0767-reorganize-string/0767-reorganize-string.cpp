class Solution {
public:
    string reorganizeString(string s) {
        string ans="";
        priority_queue<pair<int,char>> pq;
        map<char,int> mp;
        for(auto i:s){
            mp[i]++;
        }
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        while(!pq.empty() and pq.size()>=2){
            auto one = pq.top();pq.pop();
            auto two = pq.top();pq.pop();
            ans+=one.second;
            ans+=two.second;
            one.first--;
            two.first--;
            if(one.first>0) pq.push(one);
            if(two.first>0) pq.push(two);
        }
        if(!pq.empty()){
            if(pq.top().first>1) return "";
            ans+=pq.top().second;
        }
        return ans;
    }
};