class Solution {
public:
    //Refer  : https://1e9.medium.com/monotonic-queue-notes-980a019d5793#bfcd
    //Using monotonic queue - increasing one
    int shortestSubarray(vector<int>& arr, int k) 
    {
        int n=arr.size();
        vector<int>pref(n+1,0);
       
        for(int i=0; i<n; i++)pref[i+1]=pref[i]+arr[i];
        
        
        deque<pair<int,int>>dq ; //(pref[i],i)-Will maintain a montonically - increasing queue
        int len=INT_MAX;
        for(int i=0; i<=n; i++)
        {
           
            while(!dq.empty() and pref[i]<=dq.back().first)
                dq.pop_back();
            
            while(!dq.empty() and pref[i]-dq.front().first>=k)
            {
                len=min(len,i-dq.front().second);
                dq.pop_front();
            }
            
            dq.push_back({pref[i],i});
        }
        
        return len==INT_MAX ? -1 : len;
        
    }
};