class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr)
    {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        if(n==1)
            return 1;
        arr[0]=1;
        int maxi=arr[0];
        for(int i=1; i<n; i++)
        {
            if(arr[i]-arr[i-1]>1)
                arr[i]=arr[i-1]+1;
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }
};