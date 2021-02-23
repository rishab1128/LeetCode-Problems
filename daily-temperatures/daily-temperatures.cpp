class Solution 
{
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }

    vector<int> dailyTemperatures(vector<int>& T) 
    {
        int n=T.size();
        vector<int>ans(n);
        stack<int>st;
        st.push(0);
        map<int,int>mp;
        for(int i=1; i<n; i++)
        {
            int next=T[i];
            while(st.size()>0 && next > T[st.top()])
            {
                mp[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            mp[st.top()]=-1;
            st.pop();
        }
        for(int i=0; i<n; i++)
        {
            if(mp[i]!=-1)
                ans[i]=mp[i]-i;
            else
                ans[i]=0;
        }
        return ans;
    }
};