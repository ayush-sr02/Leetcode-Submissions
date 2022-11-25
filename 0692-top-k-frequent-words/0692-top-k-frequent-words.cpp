

class Solution {
public:
    // Custom comparator for ordering of priority queue ***IMP***
    struct comparator{
        bool operator()(pair<int,string> &p1,pair<int,string> &p2){
            if(p1.first > p2.first) return false;
            else if(p1.first == p2.first) return p1.second > p2.second;
            else return true;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        map<string,int> mp;
        for(string i:words){
            mp[i]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,comparator> pq;
        for(auto i:mp){
            pq.push(make_pair(i.second,i.first));
        }
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};