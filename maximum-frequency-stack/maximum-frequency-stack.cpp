struct S
{
    int m_n1;
    int m_n2;
    int m_n3;

    S(int n1, int n2, int n3) : m_n1(n1), m_n2(n2), m_n3(n3)
    {
    }

    bool operator<(const struct S& other) const
    {
        //Your priority logic goes here
        return m_n1 < other.m_n1;
    }
};

class FreqStack {
public:
    
    priority_queue<pair<int, pair<int, int>>> pq;
    unordered_map<int,int>mp;
    int pos=0;
    
    FreqStack() {
        
    }
    
    void push(int val) 
    {
        mp[val]++;
        // pos=pq.size() +1;
        pos++;
        pq.push({mp[val] , {pos , val}});
        
    }
    
    int pop() 
    {
//         priority_queue<pair<int, pair<int, int>>> tq=pq;
//         while(tq.size()>0)
//         {
//             auto s1 = tq.top();
//             tq.pop();

//             int freq=s1.first;
//             int posi=s1.second.first;
//             int val=s1.second.second;
            
//             cout<<val<<" "<<posi<<" "<<freq<<endl;
//         }
//         cout<<"-----------------------"<<endl;
        auto s1 = pq.top();
        pq.pop();
        
        int freq=s1.first;
        int posi=s1.second.first;
        int val=s1.second.second;
        
        mp[val]--;
        
        return val;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */