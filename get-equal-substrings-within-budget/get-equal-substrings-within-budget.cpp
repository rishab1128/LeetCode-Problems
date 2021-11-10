class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int n=s.size();
        vector<int>arr(n);
        for(int i=0; i<n; i++)
        {
            int x=(int)s[i] , y=(int)t[i];
            arr[i]=abs(x-y);
        }
        
        //Find the longest subarray in arr such that the sum of the subarray <= maxCost
        int left=0,right=0,sum=0,ans=0;
        while(right<n)
        {
            sum+=arr[right];
            while(sum>maxCost)
                sum-=arr[left++];
            ans=max(ans,right-left+1);
            right++;
        }
        
        return ans;
        
    }
};