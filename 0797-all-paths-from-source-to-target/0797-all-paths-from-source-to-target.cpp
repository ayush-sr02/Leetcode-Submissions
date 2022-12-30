class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    int target;
    
    void dfs(vector<vector<int>> graph,int curNode){
        temp.push_back(curNode);
        if(curNode==target) ans.push_back(temp);
        else{
            for(auto it:graph[curNode]) dfs(graph,it);
        }
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target=graph.size()-1;
        dfs(graph,0);
        return ans;
    }
};