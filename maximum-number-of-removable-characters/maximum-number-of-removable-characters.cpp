class Solution {
public:
    bool check(string s, string p , vector<int>& remo , int k)
    {
        for(int i=0; i<=k; i++)
        {
            int idx=remo[i];
            s[idx]='*';
        }
        
        //Check whether p is a subseq of s or not
        int j=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]==p[j])
                j++;
        }
        
        return j==p.size();
        
    }
    
    int maximumRemovals(string s, string p, vector<int>& remo) 
    {
        //Applying BS on Answer
        
        int lo=0,hi=remo.size()-1,ans=0;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(check(s,p,remo,mid))
            {
                ans=mid+1;
                lo=mid+1;
            }
            else
                hi=mid-1;
            
        }
        
        return ans;
    }
};