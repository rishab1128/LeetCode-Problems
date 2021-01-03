    {
        int n=arr.size();
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        //min-heap pq-->stores the apples with the earliest expiration date on the top along with the no.of apples
        int i=0,ans=0;
        while(i<n||pq.size())
        {
            if(i<n&&arr[i]>0)pq.push({i+days[i]-1,arr[i]});
​
            while(pq.size()&&pq.top().FF<i)pq.pop();
​
            if(pq.size())
            {
                int apples=pq.top().SS;
                int day=pq.top().FF;
                pq.pop();
                if(apples>1)pq.push({day,apples-1});
                ans++;
            }
            i++;
        }
        return ans;  
    }
};
