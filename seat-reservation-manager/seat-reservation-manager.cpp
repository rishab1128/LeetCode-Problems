class SeatManager {
public:
    priority_queue<int>pq;
    SeatManager(int n) 
    {
        for(int i=1; i<=n; i++)
            pq.push(-1*i);
    }
    
    int reserve() {
        int ans=pq.top();
        pq.pop();
        return -1*ans;
    }
    
    void unreserve(int seat) {
        pq.push(seat*-1);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */