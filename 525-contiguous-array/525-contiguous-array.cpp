class Solution {
public:
    int findMaxLength(vector<int>& arr) 
    {
        int n=arr.size() , cnt=0, ans=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0; i<n; i++)
        {
            cnt+= arr[i] ? 1 : -1;
            // if(cnt==0)
            //     ans=max(ans,i+1);
            if(mp.find(cnt)==mp.end())
                mp[cnt]=i;
            else
                ans=max(ans,i-mp[cnt]);
        }
        
        return ans;
    }
};