class Solution {
public:
    typedef pair<int,int> p;
    #define ll long long
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<int> ans;
        priority_queue<p,vector<p>,greater<>> pq;
        // add indices of the tasks to the given array so that they are not lost after sorting the array.
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }
        //sort the tasks array acc to arrival time.
        sort(tasks.begin(),tasks.end());
        int i=0;
        //start from the first available task
        ll curTime=tasks[0][0];
        
        while(i<n or !pq.empty()){
            // if at current time the CPU is idle then change curTime to the first available task
            if(pq.empty()){
                curTime = max(curTime,(ll)tasks[i][0]);
            }
            
            //then add all the processes for which arrival time is less than curTime i.e tasks which are                 available to process.
            // pq will sort available tasks acc to the burst time as given in the condition.
            while(i<n and tasks[i][0]<=curTime){
                pq.push(make_pair(tasks[i][1],tasks[i][2]));
                i++;
            }
            //pick the first task from pq and add it to ans array, then add its processing time to curTime.
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.second);
            curTime+=top.first;
        }
        return ans;
    }
};