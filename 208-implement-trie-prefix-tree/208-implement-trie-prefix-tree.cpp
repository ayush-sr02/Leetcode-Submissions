class Trie {
public:
    map<string,int> mp;
    Trie() {
        
    }
    
    void insert(string word) {
        mp[word]++;
    }
    
    bool search(string word) {
        if(mp.find(word)!=mp.end()) return true;
        return false;
    } 
    
    bool startsWith(string prefix) {
        int l=prefix.size();
        for(auto i:mp){
            if(i.first.size()<l) continue;
            string temp=i.first.substr(0,l);
            if(temp==prefix) return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */