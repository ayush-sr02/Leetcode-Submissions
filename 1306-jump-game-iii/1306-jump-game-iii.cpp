class Solution {
public:
    
    
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int> vis(n,0);
        vis[start]=1;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(arr[node]==0) return true;
            int left = node-arr[node];
            int right = node+arr[node];
            if(left>=0 and !vis[left]){
                q.push(left);
                vis[left]=1;
            }
            if(right<n and !vis[right]){
                q.push(right);
                vis[right]=1;
            }
        }
        return false;
    }
};