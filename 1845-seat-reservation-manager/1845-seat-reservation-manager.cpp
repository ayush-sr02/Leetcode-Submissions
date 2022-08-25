class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    SeatManager(int n) {
        int k=n;
        while(k--) pq.push(k);
    }
    
    int reserve() {
        int temp=pq.top();
        pq.pop();
        return temp+1;
    }
    
    void unreserve(int seatNumber){
        pq.push(seatNumber-1);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */