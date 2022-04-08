class KthLargest {
public:
    priority_queue<int>pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto x: nums){
            pq.push(-x);
        }
        while(pq.size()>k)
            pq.pop();
    }
    
    int add(int val) {
        pq.push(-val);
        while(pq.size()>k)
            pq.pop();
        int ans=pq.top();
        return -ans;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */