class MyCalendar {
public:
    map<int,int>mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) 
    {
        bool flag=1;
        mp[start]++;
        mp[end]--;
        int last = 0;
        for(auto [ele,freq] : mp){
            last+=freq;
            if(last>1)
            {
                flag=0;
                break;
            }
        }
        if(!flag)
        {
            mp[start]--;
            mp[end]++;
        }
        return flag;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */