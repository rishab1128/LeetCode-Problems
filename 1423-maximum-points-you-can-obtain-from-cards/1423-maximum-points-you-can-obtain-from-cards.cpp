class Solution {
public:
    int maxScore(vector<int>& arr, int k) 
    {
        int n=arr.size();
        int ss=n-k;
        int sum=accumulate(arr.begin(),arr.end(),0);
        int s=0; //sliding window sum
        for(int i=0; i<ss; i++)
        {
            s+=arr[i];
        }
        int ans=sum-s;
        for(int i=1; i<=k; i++)
        {
            s-=arr[i-1];
            s+=arr[i+ss-1];
            ans=max(ans,sum-s);
        }
        return ans;
        
        
    }
};