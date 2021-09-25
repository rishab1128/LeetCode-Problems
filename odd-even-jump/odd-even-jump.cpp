class Solution {
public:
    int oddEvenJumps(vector<int>& arr) 
    {
        int n=arr.size();
        map<int,int>mp;
        set<int>st;
        vector<pair<int,int>>suff(n);
        
        suff[n-1]={1,1};
        st.insert(arr[n-1]);
        mp[arr[n-1]]=n-1;
        int ct=1;
        
        for(int i=n-2; i>=0; i--)
        {
            auto it1=st.lower_bound(arr[i]);
            if(it1!=st.end())
            {
                int n1=(*it1);
                int pos1=mp[n1];
                if((*it1)==arr[i])
                {
                    suff[i].first=suff[pos1].second;
                    suff[i].second=suff[pos1].first;
                }
                else if((*it1)!=arr[i] and it1!=st.begin())
                {
                    it1--;
                    int n2=(*it1);
                    int pos2=mp[n2];
                    suff[i].first=suff[pos1].second;
                    suff[i].second=suff[pos2].first;
                }
                else if((*it1)!=arr[i] and it1==st.begin())
                {
                    suff[i].first=suff[pos1].second;
                    suff[i].second=0;
                }
            }
            else
            {
                it1--;
                int n2=(*it1);
                int pos2=mp[n2];
                suff[i].first=0;
                suff[i].second=suff[pos2].first;   
            }
            
            if(suff[i].first)
                ct++;
            
            st.insert(arr[i]);
            if(mp.find(arr[i])!=mp.end())
                mp[arr[i]]=min(i,mp[arr[i]]);
            else
                mp[arr[i]]=i;
        }
        
        for(auto x: suff)
            cout<<"("<<x.first<<","<<x.second<<") ";
        cout<<endl;
        
        
        return ct;
        
        
    }
};