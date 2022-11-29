class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> v;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
            mp[val]=v.size();
            v.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end()){
            swap(v[v.size()-1],v[mp[val]]);
            v.pop_back();
            mp[v[mp[val]]] = mp[val];
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */