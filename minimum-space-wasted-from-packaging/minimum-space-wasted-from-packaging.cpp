const int mod=1e9+7;
class Solution {
public:
    int minWastedSpace(vector<int>& packs, vector<vector<int>>& boxes) 
    {
        long n=packs.size();
        sort(packs.begin(),packs.end());
        
        long pref[n];
        pref[0]=packs[0];
        for(int i=1; i<n; i++)
            pref[i]=(pref[i-1]+packs[i]);
        
        long m=boxes.size();
        long ans=LONG_MAX;
        for(long i=0; i<m; i++)
        {
            sort(boxes[i].begin(),boxes[i].end());
            long sz=boxes[i].size();
            if(boxes[i][sz-1]>=packs[n-1])
            {
                long last=-1,tmp=0;
                for(long j=0; j<sz; j++)
                {
                    long pos=upper_bound(packs.begin(),packs.end(),boxes[i][j])-packs.begin()-1;
                    if(pos>=0 and pos<n)
                    {
                        if(last==-1)
                            tmp+=(boxes[i][j]*(pos-last))-pref[pos];
                        else
                            tmp+=(boxes[i][j]*(pos-last))-(pref[pos]-pref[last]);
                        
                        //tmp=tmp%mod;
                        last=pos;
                    }
                }
                ans=min(ans,tmp);
            }
        }
        
        return ans==LONG_MAX?-1:ans%mod;
        
    }
    
    
};