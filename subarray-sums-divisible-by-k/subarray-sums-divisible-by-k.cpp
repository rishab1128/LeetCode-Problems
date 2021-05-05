class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) 
    {
        int n=arr.size();
        vector<int>rem(k,0); 
        int cumu=0;
        for(int i=0; i<n; i++)
        {
            cumu+=arr[i];
            rem[((cumu%k)+k)%k]++;
        }
        long long ans=0;
        for(int i=0; i<k; i++)
        {
            if(rem[i]>1)
                ans+=(rem[i]*(rem[i]-1)/2);
        }
        return ans+rem[0];
        
    }
};