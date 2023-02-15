class Solution {
public:
    int strStr(string haystack, string needle) {
        auto x = haystack.find(needle);
        if(x!=string::npos) return x;
        return -1;
    }
};