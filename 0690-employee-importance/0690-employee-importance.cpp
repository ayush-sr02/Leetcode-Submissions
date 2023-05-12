/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    vector<int> tree[2001];
    
    int solve(int node,int par,vector<int> &req,vector<int>&imp){
        int cur=0;
        for(auto i:tree[node]){
            if(i!=par){
                cur+=(imp[i]+solve(i,node,req,imp));
            }
        }
        return req[node] += cur;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        vector<int> req(2001);
        vector<int> imp(2001);
        
        for(int i=0;i<n;i++){
            auto x = employees[i];
            imp[x->id] = x->importance;
            for(auto j:x->subordinates){
                tree[x->id].push_back(j);
            }
        }
        
        solve(id,0,req,imp);
        return req[id]+imp[id];
    }
};