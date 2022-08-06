class Solution {
public:
    int poorPigs(int buckets, int ded, int total) {
        int test = total/ded;
        int i=0;
        while(pow(test+1,i)<buckets) i++;
        return i;
    }
};