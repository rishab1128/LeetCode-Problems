class Solution {
public:
    
    int minMeetingRooms(vector<vector<int>>& inter) 
    {
        sort(inter.begin(), inter.end());
        multiset<int>st;
        st.insert(inter[0][1]);
        int cnt = 1;
        for(int i=1; i<inter.size(); i++)
        {
            int start = inter[i][0] ,  end = inter[i][1];
            
            if(start>=*st.begin())
                st.erase(st.begin());
            else
                cnt++;
            
            st.insert(end);
        }
        
        return cnt;
    }
};