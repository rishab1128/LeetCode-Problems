class Solution {
public:
    int longestMountain(vector<int>& arr) 
    {
        int n=arr.size();
        int left[n],right[n];
        left[0]=0;
        for(int i=1; i<n; i++)
        {
            if(arr[i]>arr[i-1])
                left[i]=left[i-1];
            else
                left[i]=i;
        }
        right[n-1]=n-1;
        for(int i=n-2; i>=0; i--)
        {
            if(arr[i]>arr[i+1])
                right[i]=right[i+1];
            else
                right[i]=i;
        }
        int ans=0,maxi=0;
        for(int i=1; i<n-1; i++)
        {
            if(left[i]!=i and right[i]!=i)
                maxi=(i-left[i])+(right[i]-i)+1;
            ans=max(ans,maxi);
        }
        return ans<=2?0:ans;
        
    }
};