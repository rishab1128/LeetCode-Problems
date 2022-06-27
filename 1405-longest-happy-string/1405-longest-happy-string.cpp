class Solution {
public:
    string longestDiverseString(int a, int b, int c) 
    {
        priority_queue<pair<int,char>>pq;
        if(a>0)
            pq.push({a,'a'});
        if(b>0)
            pq.push({b,'b'});
        if(c>0)
            pq.push({c,'c'});
        
        string ans = "";
        while(pq.size()>1)
        {
            auto [freq1, ch1] = pq.top();
            pq.pop();
            auto [freq2 , ch2] = pq.top();
            pq.pop();
            
            ans+=ch1;
            freq1--;
            if(freq1>=1){
                ans+=ch1;
                freq1--;
            }
                
            ans+=ch2;
            freq2--;
            if(freq2>=1 and freq2>=freq1){
                ans+=ch2;
                freq2--;
            }
            
            if(freq1>0)
                pq.push({freq1,ch1});
            if(freq2>0)
                pq.push({freq2,ch2});
        }
        
        if(pq.empty())
            return ans;
        
        auto [freq1, ch1] = pq.top();
        
        ans+=ch1;
        freq1--;
        if(freq1>=1)
            ans+=ch1;
        
    
        return ans;
        
    }
};