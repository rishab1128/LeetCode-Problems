class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int>ans;
    MedianFinder() {
        
    }
    
    void addNum(int val) {
         if(ans.size()==0)
            ans.push_back(val);
        else
            ans.insert(lower_bound(ans.begin(), ans.end(), val), val);
    }
    
    double findMedian() {
        int n = ans.size();
        if(n%2)
            return ans[n / 2];
        else
        return ((double) ans[n / 2 - 1] + ans[n / 2]) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */