class MyCalendarTwo {
    
private: map<int,int>mp;
public:
    MyCalendarTwo() {
        mp.clear();
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int numOfOngoingEvents = 0;
        for(auto [time, cnt] : mp)
        {
            numOfOngoingEvents += cnt;
            if(numOfOngoingEvents==3)
            {
                mp[start]--;  //unbook that event
                mp[end]++;    //unbook that event
                return false;
            }
        }
    
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */