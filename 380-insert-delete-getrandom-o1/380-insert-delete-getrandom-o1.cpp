class RandomizedSet {
public:
    vector<int>arr;
    map<int,int>mp;
    RandomizedSet() {
        arr.clear();
        mp.clear();
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end())
        {
            arr.push_back(val);
            mp[val]=arr.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) 
    {
        if(mp.find(val)==mp.end())
            return false;
        
        int n =arr.size() , last=arr[n-1] ;
        int pos=mp[val];
        mp[last]=pos;
        mp.erase(val);
        swap(arr[n-1], arr[pos]);
        arr.pop_back();
        
        return true;
    }
    
    int getRandom() {
        int n=arr.size();
        int idx=rand()%n;
        return arr[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */