class FindSumPairs {
private:
    unordered_map<int,int> mp;
    vector<int> n,m;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n=nums1;
        m=nums2;
        for(auto i:m) mp[i]++;
    }
    
    void add(int index, int val) {
        mp[m[index]]--;
        m[index]+=val;
        mp[m[index]]++;
    }
    
    int count(int tot) {
        int cnt=0;
        for(int i=0;i<n.size();i++){
            cnt+=mp[tot-n[i]];
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */