class Solution {
public:
    vector<int> t,ori;
    Solution(vector<int>& nums) {
        t=nums;
        ori=nums;
    }
    
    vector<int> reset() {
        t=ori;
        return t;
    }
    
    vector<int> shuffle() {
        random_shuffle(t.begin(),t.end());
        return t;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */