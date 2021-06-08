class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) 
    {
        int curr=0;
        if(st.empty())
        {
            st.push({price,1});
            return 1;
        }
        else if(st.top().first>price)
        {
            st.push({price,1});
            return 1;
        }
        else
        {
            while(st.size()>0 and st.top().first<=price)
            {
                curr+=st.top().second;
                st.pop();
            }
            st.push({price,curr+1});
        }
        return curr+1;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */