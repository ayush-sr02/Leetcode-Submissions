class Solution {
public:
    
    struct comparator{
        bool operator()(string &a,string &b){
            if(a.size()>b.size()) return false;
            if(a.size()<b.size()) return true;
// when both strings are of equal sizes compare them from left to right and whenever there is inequality return true/false accordingly.
            
            for(int i=0;i<a.size();i++){
                if(a[i]-'0'>b[i]-'0') return false;
                else if(a[i]-'0'<b[i]-'0') return true;
            }
            return true;
        }
    };
    
    
    // custom comparator to sort the vector 
    // static bool compare(string &a,string &b){
    //     if(a.size()==b.size()){
    //         return a<b;
    //     }
    //     return a.size()<b.size();
    // }
    
    string kthLargestNumber(vector<string>& nums, int k) {
        
        priority_queue<string,vector<string>,comparator> pq(nums.begin(),nums.end());
        k-=1;
        while(k--) pq.pop();
        return pq.top();
        
        // using custom comparator to sort the array.
        // sort(nums.begin(),nums.end(),compare);
        // return nums[nums.size()-k];
    }
};