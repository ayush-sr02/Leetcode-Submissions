class LUPrefix {
public:
    vector<int> v;
    int lng = 0;
    int i=1;
    LUPrefix(int n) {
        v.resize(n+1,0);
    }
    
    void upload(int video) {
        v[video]=1;
        while(i<v.size() and v[i]!=0){
            i++;
        }
        lng=i-1;
    }
    
    int longest() {
        return lng;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */