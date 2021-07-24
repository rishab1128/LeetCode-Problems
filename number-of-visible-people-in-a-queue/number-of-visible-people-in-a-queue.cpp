class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& hts) 
    {
        if(hts.size()==1)
            return {0};
        int n=hts.size();
        vector<int>ans(n);
        stack<int>st;
        ans[n-1]=0;
        st.push(hts[n-1]);
        for(int i=n-2; i>=0; i--)
        {
            int ct=0;
            while(st.size()>0 and hts[i]>st.top())
            {
                ct++;
                st.pop();
            }
            if(st.size()>0)
                ans[i]=ct+1;
            else
                ans[i]=ct;
            st.push(hts[i]);
        }
        return ans;
        
    }
};