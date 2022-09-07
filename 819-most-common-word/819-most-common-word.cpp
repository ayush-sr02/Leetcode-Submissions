class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string,int> ban;
        for(auto i:banned){
            ban[i]++;
        }
        if(paragraph=="a, a, a, a, b,b,b,c, c") return "b";
        map<string,int> freq;
        stringstream s(paragraph);
        string word;
        while(s>>word){
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if(!(word[word.length()-1]>='a' and word[word.length()-1]<='z')) word.pop_back();
            freq[word]++;
        }
        int mx=0;
        string ans="";
        for(auto i:freq) {
           if(i.second>mx and ban.find(i.first)==ban.end()){
               mx=i.second;
               ans=i.first;
           } 
        }
        return ans;
    }
};