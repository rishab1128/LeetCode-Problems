using ll=long long;
class Bank {
public:
    map<ll,ll>mp;
    vector<ll>arr;
    Bank(vector<long long>& balance) {
        arr=balance;
        int n=arr.size();
        for(int i=0; i<n; i++)
            mp[i+1]=arr[i];
    }
    
    bool transfer(int acc1, int acc2, long long money) 
    {
        if(mp.find(acc1)!=mp.end() and mp.find(acc2)!=mp.end() and mp[acc1]>=money)
        {
            mp[acc1]-=money;
            mp[acc2]+=money;
            return true;
        }
        return false;
        
    }
    
    bool deposit(int acc, long long money) {
        
        if(mp.find(acc)!=mp.end()){
            mp[acc]+=money;
            return true;
        }
        return false;
            
        
    }
    
    bool withdraw(int acc, long long money) {
        
        if(mp.find(acc)!=mp.end() and mp[acc]>=money)
        {
            mp[acc]-=money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */