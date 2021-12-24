bool cmp(const vector<int>&a , const vector<int>&b)
{
    return a[0]<b[0];
}
class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& inter) 
    {
        int n=inter.size();
        sort(inter.begin(),inter.end(),cmp);
        stack<vector<int>>st;
        st.push(inter[0]);
        for(int i=1; i<n; i++)
        {
            auto r=st.top();
            if(inter[i][0]<=r[1])
            {
                st.pop();
                r[1]=max(r[1],inter[i][1]);
                st.push(r);
            }
            else
                st.push(inter[i]);
        }
        vector<vector<int>>ans;
        while(st.size()>0)
            ans.push_back(st.top()),st.pop();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};