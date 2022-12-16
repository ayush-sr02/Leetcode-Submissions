class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        int n=pre.size();
        vector<int> adj[num];
        vector<int> indegree(num,0);
        for(int i=0;i<n;i++){
            adj[pre[i][0]].push_back(pre[i][1]);
            indegree[pre[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<num;i++)
            if(indegree[i]==0)
                q.push(i);
        // vector<int> topo;
        int cnt=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            // topo.push_back(node);
            cnt++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        // return topo.size()==num;
        return cnt==num;
    }
};