class FreqStack {
public:
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>mp;
    int mxfreq=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        mxfreq=max(mxfreq,freq[val]);
        mp[freq[val]].push(val);
    }
    
    int pop() 
    {
        int val=mp[mxfreq].top();
        mp[mxfreq].pop();
        freq[val]--;
        if(mp[mxfreq].size()==0)
            mxfreq--;
        return val;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */