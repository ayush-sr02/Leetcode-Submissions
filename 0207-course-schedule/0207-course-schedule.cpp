class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& p) {
        vector<int> indegree(num,0);
        vector<int> adj[num];

        for(auto i:p){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int> q;
        vector<int> topo;
        
        for(int i=0;i<num;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int top = q.front(); q.pop();
            topo.push_back(top);
            for(auto it:adj[top]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return topo.size()==num;
    }
};