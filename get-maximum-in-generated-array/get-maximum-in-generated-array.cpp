class Solution {
public:
    int getMaximumGenerated(int n) 
    {
        if(n==0)
            return 0;
        vector<int>arr(n+1);
        arr[0]=0,arr[1]=1;
        for(int i=1; 2*i+1<=n; i++)
        {
            arr[2*i]=arr[i];
            arr[2*i+1]=arr[i]+arr[i+1];
        }
        sort(arr.rbegin(),arr.rend());
        return arr[0];
        
    }
};