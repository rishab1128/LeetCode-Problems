class MKAverage {
public:
    multiset<int>top,mid,bot;
    queue<int>q;
    int sum=0,m,k;
    MKAverage(int m, int k) {
        this->m=m;
        this->k=k;
    }
    
    void addElement(int num) 
    {
        //Case 1: 
        if(q.size()<m)
        {
            mid.insert(num);
        }
        
        q.push(num);
        
        //Case 2:
        if(q.size()==m)
        {
            //Inserting smallest k elements in "bottom set" 
            for(int i=0; i<k; i++)
            {
                bot.insert(*mid.begin());
                mid.erase(mid.begin());
            }
            
            //Inserting largest k elements in "top set"
            for(int i=0; i<k; i++)
            {
                top.insert(*mid.rbegin());
                mid.erase(prev(mid.end()));
            }
            
            for (int x : mid) sum += x;
        }
        
        //Case 3:
        else if(q.size()>m)
        {
            //Adjust for the recently added element in the stream
            if(num<*bot.rbegin())
            {
                int x=*bot.rbegin();
                bot.erase(prev(bot.end()));
                bot.insert(num);
                mid.insert(x);
                sum+=x;
            }
            else if(num>*top.begin())
            {
                int x=*top.begin();
                top.erase(top.begin());
                top.insert(num);
                mid.insert(x);
                sum+=x;
            }
            else
            {
                mid.insert(num);
                sum+=num;
            }
            
            //Now remove that one outdated element from the queue and the "mid set"
            int rm=q.front();
            q.pop();
            if(mid.find(rm)!=mid.end())
            {
                mid.erase(mid.find(rm));
                sum-=rm;
            }
            else if(top.find(rm)!=top.end())
            {
                top.erase(top.find(rm));
            }
            else
                bot.erase(bot.find(rm));
            
            
            // Lastly, balance `top` and `bot`(so that their size is always =k ) if needed
            if(top.size()<k)
            {
                int x=*mid.rbegin();
                top.insert(*mid.rbegin());
                mid.erase(prev(mid.end()));
                sum-=x;
            }
            else if(bot.size()<k)
            {
                int x=*mid.begin();
                bot.insert(*mid.begin());
                mid.erase(mid.begin());
                sum-=x;
            }
            
        }
        
    }
    
    int calculateMKAverage() {
        if(q.size()==m)
            return sum/(m-2*k);
        return -1;
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */