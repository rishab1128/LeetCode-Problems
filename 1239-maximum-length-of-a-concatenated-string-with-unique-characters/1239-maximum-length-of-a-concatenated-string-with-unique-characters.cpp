class Solution {
public:
    int maxLength(vector<string>& arr) 
    {
        int n=arr.size() , ans=0;
        for(int i=0; i<(1<<n); i++)
        {
            int n1=i , tmp=0, flag=1;
            vector<bool>mp(26,0);
            for(int j=0; j<n; j++)
            {
                int n2=(1<<j);
                if(n1&n2)
                {
                    tmp+=(int)arr[j].size();
                    for(auto ch: arr[j])
                    {
                        int x=ch-'a';
                        if(!mp[x])
                            mp[x]=1;
                        else
                        {
                            flag=0;
                            break;
                        }
                    }
                }
                if(!flag)
                    break;
            }
            if(flag)
                ans=max(ans,tmp);
        }
        return ans;
    }
};