class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    SeatManager(int n) {
        while(n--) pq.push(n+1);
    }
    
    int reserve() {
        int temp=pq.top();
        pq.pop();
        return temp;
    }
    
    void unreserve(int seatNumber){
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */