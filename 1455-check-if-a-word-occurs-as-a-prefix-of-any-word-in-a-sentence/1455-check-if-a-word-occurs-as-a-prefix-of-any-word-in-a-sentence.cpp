class Solution {
public:
    int isPrefixOfWord(string str, string target) {
        int cnt=0;
        stringstream s(str);
        int l=target.length();
        string word;
        while(s>>word){
            int ll=word.length();
            cnt++;
            if(ll<l) continue;
            string temp = word.substr(0,l);
            if(temp==target) return cnt;
        }
        return -1;
    }
};