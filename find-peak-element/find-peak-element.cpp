class Solution {
public:
    //O(N) Algo
    int findPeakElement(vector<int>& arr) 
    {
        int n=arr.size() ;
        if(n==1)
            return 0;
        int ans=-1;
        if(arr[0] > arr[1])
            return 0;
        if(arr[n-1]>arr[n-2])
            return n-1;
        
        for(int i=1; i<=n-2; i++)
        {
            if(arr[i]>arr[i-1] and arr[i]>arr[i+1])
            {
                ans=i;
                break;
            }
                
        }
        
        return ans;
        
        
        
        
    }
};