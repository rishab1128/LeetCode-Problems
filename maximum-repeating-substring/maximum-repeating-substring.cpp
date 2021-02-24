class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int maxRepeating(string s, string t) 
    {
        int n=s.size() , m=t.size(), ans=0;
        for(int i=0; i<=n-m; i++)
        {
            int st=i,ct=0;
            if(s.substr(st,m)==t)
            {
                while(st<=n-m&&s.substr(st,m)==t)
                {
                    st+=m;
                    ct++;
                    //cout<<"Y"<<" "<<i<<endl;
                }
            }
            ans=max(ans,ct);
        }
        return ans;
        
    }
};