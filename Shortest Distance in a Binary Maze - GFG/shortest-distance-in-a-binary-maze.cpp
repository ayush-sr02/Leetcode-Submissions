//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
  vector<pair<int,int>> movement = {{0,1},{0,-1},{-1,0},{1,0}};
  
  bool valid(int i,int j,int n,int m){
      return i>=0 and j>=0 and i<n and j<m;
  }
  
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> des) {
        // code here
        int n=grid.size(),m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        q.push({{source.first,source.second},0});
        while(!q.empty()){
            pair<int,int> p = q.front().first;
            int dis = q.front().second;
            q.pop();
            if(p==des) return dis;
            for(auto i:movement){
                int xd = p.first+i.first;
                int yd = p.second+i.second;
                if(valid(xd,yd,n,m) and grid[xd][yd]==1){
                    grid[xd][yd]=0;
                    q.push({{xd,yd},dis+1});
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends