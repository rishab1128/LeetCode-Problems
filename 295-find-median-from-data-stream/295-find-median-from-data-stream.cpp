//maxHeap stores all the low numbers (left part of the median of a sorted array) -> top of maxHeap gives the max among all the low numbers

//minHeap stores all the high numbers (right part of the median of a sorted array) -> top of minHeap gives the min among all the high numbers

class MedianFinder {
private: priority_queue<int>maxHeap;
         priority_queue<int,vector<int>,greater<>>minHeap;
public:
    MedianFinder() {
        
    }
    
    //O(log n)
    void addNum(int x) 
    {
        if(maxHeap.empty() || x<maxHeap.top())
            maxHeap.push(x);
        else
            minHeap.push(x);
        
        if((int)maxHeap.size()-(int)minHeap.size()>1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if((int)minHeap.size()-(int)maxHeap.size()>1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    //O(1)
    double findMedian() {
        
        if((int)maxHeap.size()>(int)minHeap.size())
            return (double)maxHeap.top();
        
        if((int)minHeap.size()>(int)maxHeap.size())
            return (double)minHeap.top();
        
        return (double)(maxHeap.top()+minHeap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */