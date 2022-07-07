class Solution {
public:
    
    int minMeetingRooms(vector<vector<int>>& inter) 
    {
        sort(inter.begin(), inter.end());
        priority_queue<int,vector<int>,greater<>>pq; //stores the minimum end time 
        pq.push(inter[0][1]);
        int cnt = 1;
        for(int i=1; i<inter.size(); i++)
        {
            int start = inter[i][0] ,  end = inter[i][1];
            
            if(start>=pq.top())
                pq.pop();
            else
                cnt++;
            
            pq.push(end);
        }
        
        return cnt;
    }
};