//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int d) {
        vector<vector<int>> dis(n,vector<int> (n,1e9));
        for(auto i:edges){
            int x=i[0],y=i[1],z=i[2];
            dis[x][y]=z;
            dis[y][x]=z;
        }
        for(int i=0;i<n;i++){
            dis[i][i]=0;
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dis[i][j] = min(dis[i][j],(dis[i][via]+dis[via][j]));
                }
            }
        }
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i!=j and dis[i][j]<=d) cnt++;
            }
            v[i]=cnt;
        }
        int ans=0;
        int mn=1e9;
        for(int i=0;i<n;i++){
            if(v[i]<=mn){
                ans=i;
                mn=v[i];
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends