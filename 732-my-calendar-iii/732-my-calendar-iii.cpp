class MyCalendarThree {
    
private: map<int,int>map;
public:
    
    
    
    MyCalendarThree() {
        map.clear();
    }
    
    int book(int start, int end) 
    {
        map[start]++;
        map[end]--;
        int ans = 0 , curr = 0;
        for(auto [time , cnt] : map){
            curr+=cnt;
            ans = max( ans , curr);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */