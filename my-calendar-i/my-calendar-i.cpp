class MyCalendar {
public:
    set<int>end_pts;
    map<int,int>mp; //maps ending point to corresponding starting point mp[end_pt]=start_pt;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) 
    {
        if(end_pts.empty())
        {
            end_pts.insert(end);
            mp[end]=start;
            return true;
        }
        else
        {
            auto it=end_pts.upper_bound(start);
            if(it==end_pts.end())
            {
                end_pts.insert(end);
                mp[end]=start;
                return true;
            }
            else
            {
                int endi=(*it);
                int starti=mp[endi];
                if(starti>=end)
                {
                    end_pts.insert(end);
                    mp[end]=start;
                    return true;   
                }
            }
        }
        return false;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */