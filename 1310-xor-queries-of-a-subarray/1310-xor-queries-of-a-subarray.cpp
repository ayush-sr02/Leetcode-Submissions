class Solution {
public:
    vector<int> segment;
    
    void buildTree(int start,int end,vector<int> &arr,int idx){
        if(start>end) return;
        if(start==end){
            segment[idx]=arr[start];
            return;
        }
        int mid = start+(end-start)/2;
        buildTree(start,mid,arr,2*idx);
        buildTree(mid+1,end,arr,2*idx+1);
        segment[idx] = segment[2*idx]^segment[2*idx+1];
    }
    
    int query(int start,int end,int l,int r,int idx){
        if(start>r or end<l) return 0;
        if(start>=l and end<=r){
            return segment[idx];
        }
        int mid = start+(end-start)/2;
        int left = query(start,mid,l,r,2*idx);
        int right = query(mid+1,end,l,r,2*idx+1);
        return left^right;
    }
    
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        segment.resize(4*n,0);
        buildTree(0,n-1,arr,1);
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            ans[i] = query(0,n-1,queries[i][0],queries[i][1],1);
        }
        return ans;
    }
};