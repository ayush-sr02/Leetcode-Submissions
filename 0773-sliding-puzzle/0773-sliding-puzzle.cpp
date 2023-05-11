class Solution {
public:
    //brute force and check all possibilities until fin config is obtained
    vector<pair<int,int>> movement = {{0,1},{0,-1},{1,0},{-1,0}};
    
    bool check(int i,int j,int n,int m){
        return i>=0 and i<n and j>=0 and j<m;
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> fin = {{1,2,3},{4,5,0}};
        queue<pair<vector<vector<int>>,int>> q;
        q.push({board,0});
        map<vector<vector<int>>,int> mp;
        mp[board]=1;
        
        while(!q.empty()){
            vector<vector<int>> front = q.front().first;
            int cnt=q.front().second;
            q.pop();
            if(front==fin) return cnt;
            for(int i=0;i<2;i++){
                for(int j=0;j<3;j++){
                    if(front[i][j]==0){
                        for(auto it:movement){
                            int x = i+it.first;
                            int y = j+it.second;
                            if(check(x,y,2,3)){
                                vector<vector<int>> temp = front;
                                swap(temp[i][j],temp[x][y]);
                                if(!mp.count(temp)){
                                    q.push({temp,cnt+1});
                                    mp[temp]=1;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};