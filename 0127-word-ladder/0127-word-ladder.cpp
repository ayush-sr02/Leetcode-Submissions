// find out all possibilities by changing each character from a to z znd keep checking if that transition on possible. If so push it in queue.

//  ait->bit->...zit
//  hat->hbt->...hzt
//  hia->hib->...hic
// hot is possible so push it in queue then change each character in hot from a to z
// eventually when all combinations are checked and none leads to final string return 0


class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& word) {
        queue<pair<string,int>> q;
        q.push({begin,1});
        unordered_set<string> s(word.begin(),word.end());
        s.erase(begin);
        
        while(!q.empty()){
            string temp = q.front().first;
            int len = q.front().second;
            q.pop();
            if(temp==end) return len;
            for(int i=0;i<temp.size();i++){
                char og = temp[i];
                for(char x='a';x<='z';x++){
                    temp[i] = x;
                    if(s.find(temp)!=s.end()){
                        q.push({temp,len+1});
                        s.erase(temp);
                    }
                }
                temp[i]=og;
            }
        }
        return 0;
    }
};