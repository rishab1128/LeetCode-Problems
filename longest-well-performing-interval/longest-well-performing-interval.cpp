class Solution {
public:
    int longestWPI(vector<int>& hours) 
    {
        int n=hours.size();
        for(int i=0; i<n; i++)
        {
            if(hours[i]>8)
                hours[i]=1;
            else
                hours[i]=-1;
        }
        
        //Now find the longest subarray with sum>0
        vector<int>pref(n);
        pref[0]=hours[0];
        for(int i=1; i<n; i++)
            pref[i]=hours[i]+pref[i-1];
        
        //Make a prefMin array of the pref array
        vector<int>prefMin(n);
        prefMin[0]=pref[0];
        for(int i=1; i<n; i++)
            prefMin[i]=min(prefMin[i-1],pref[i]);
        
        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(pref[i]>0)
                ans=max(ans,i+1);
            else
            {
                int low=0,high=i-1,pos=-1;
                while(low<=high)
                {
                    int mid=low+(high-low)/2;
                    if(prefMin[mid]<pref[i])
                    {
                        pos=mid;
                        high=mid-1;
                    }
                    else
                        low=mid+1;
                }
                if(pos!=-1)
                    ans=max(ans,i-pos);
            }
        }
        
        return ans;
        
    }
};