class Solution {
public:
    int maximumUniqueSubarray(vector<int>& arr) 
    {
        int n=arr.size();
        int left=0,right=0,sum=0,ans=0;
        unordered_map<int,int>mp;
        while(right<n)
        {
            mp[arr[right]]++;
            sum+=arr[right];
            while(mp[arr[right]]==2)
            {
                sum-=arr[left];
                mp[arr[left]]--;
                if(mp[arr[left]]==0)
                    mp.erase(arr[left]);
                left++;
            }
            ans=max(ans,sum);
            right++;
        }
        return ans;
        
    }
};