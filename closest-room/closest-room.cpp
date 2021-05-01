
class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& que) 
    {
        int m=que.size() , n=rooms.size();
        for(int i=0; i<m; i++)
            que[i].push_back(i);
        auto cmp = [](const auto& r1, const auto& r2) { return r1[1] > r2[1]; };
        sort(rooms.begin(),rooms.end(),cmp);
        sort(que.begin(),que.end(),cmp);
        vector<int>ans(m);
        set<int>st;
        int j=0;
        for(int i=0; i<m; i++)
        {
            int prefer=que[i][0] , minsize=que[i][1] , idx=que[i][2];
            while(j<n and rooms[j][1]>=minsize)
                st.insert(rooms[j++][0]);
            if(st.size())
            {
                int diff=INT_MAX , res=INT_MAX;
                auto it=st.upper_bound(prefer);
                if(it!=st.end())
                {
                    diff=abs(*it-prefer);
                    res=*it;
                }
                if(it!=st.begin())
                {
                    it--;
                    if(diff>=abs(*it-prefer))
                        res=*it;
                }
                ans[idx]=res;
            }
            else
                ans[idx]=-1;
            
        }
        return ans;
        
    }
};