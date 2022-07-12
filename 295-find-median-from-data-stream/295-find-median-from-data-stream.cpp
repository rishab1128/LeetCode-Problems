class MedianFinder {
private:
    priority_queue<int>maxPq;
    priority_queue<int,vector<int>,greater<>>minPq;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        if(maxPq.empty() || num<maxPq.top())
            maxPq.push(num);
        else
            minPq.push(num);
        
       
        if((int)maxPq.size()-(int)minPq.size()>1)
        {
            minPq.push(maxPq.top());
            maxPq.pop();
        }
        else if((int)minPq.size()-(int)maxPq.size()>1)
        {
            maxPq.push(minPq.top());
            minPq.pop();
        }
    }
    
    double findMedian() 
    {
        if(maxPq.size()>minPq.size())
            return (double)maxPq.top();
        else if(minPq.size()>maxPq.size())
            return (double)minPq.top();
        
        double ans = ((double)maxPq.top()+minPq.top())/2;
        return ans;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */