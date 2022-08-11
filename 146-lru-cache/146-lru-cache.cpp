#include<bits/stdc++.h>
class LRUCache {
public:
    
    unordered_map<int,int>mp;
    unordered_map<int,list<int>::iterator>addr;
    list<int>li;
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) 
    {
        if(!mp.count(key))
            return -1;
        
        auto itr = addr[key];
        li.erase(itr);
        li.push_front(key);
        addr[key] = li.begin();
        
        return mp[key];
        
    }
    
    void put(int key, int value) 
    {
        if(!mp.count(key))
        {
            if(cap==0)
            {
                int k = li.back();
                mp.erase(k);
                addr.erase(k);
                li.pop_back();
                
                li.push_front(key);
                addr[key] = li.begin();
                mp[key] = value;
            }
            else
            {
                li.push_front(key);
                addr[key] = li.begin();
                mp[key] = value;
                cap--;
            }
        }
        else
        {
            auto itr = addr[key];
            li.erase(itr);
            mp[key] = value;
            li.push_front(key);
            addr[key] = li.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */