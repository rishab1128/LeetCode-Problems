using ll=long long;
class StockPrice {
public:
    map<ll,ll>mp;
    multiset<int> s;
    int curr;
    StockPrice() {
        mp.clear();
        s.clear();
        curr=0;
    }
    
    void update(int timestamp, int price) 
    {
        if(mp.find(timestamp)!=mp.end())
            s.erase(s.lower_bound(mp[timestamp]));
        mp[timestamp]=price;
        s.insert(price);
        curr=max(curr,timestamp);
    }
    
    int current() {
        int ans=mp[curr];
        return ans;
    }
    
    int maximum() {
        int maxi=*s.rbegin();
        return maxi;
    }
    
    int minimum() {
        int mini=*s.begin();
        return mini;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */