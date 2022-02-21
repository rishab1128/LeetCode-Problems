class Solution {
public:
    string repeatLimitedString(string s, int k) 
    {
        priority_queue<pair<char,int>>pq;
        unordered_map<char,int>mp;
        int n=s.size();
        for(auto x: s)
            mp[x]++;
        for(auto [ch,freq] : mp)
            pq.push({ch,freq});


        string ans="";
        while(ans.size()<n)
        {
            bool flag=0;
            if(pq.top().first!=ans.back())
            {
                auto [ch,freq]=pq.top();
                pq.pop();
                for(int i=0; i<min(freq,k); i++)
                    ans+=ch;
                if(freq>k)
                    pq.push({ch,freq-k});
            }
            else
            {
                auto top1=pq.top();
                pq.pop();
                if(pq.empty()){
                    flag=1;
                    break;
                }
                else
                {
                    auto [ch,freq]=pq.top();
                    pq.pop();
                    ans+=ch;
                    freq--;
                    if(freq>0)
                        pq.push({ch,freq});

                    pq.push(top1);
                }

            }

            if(flag)
                break;
        }

        return ans;

    }
};