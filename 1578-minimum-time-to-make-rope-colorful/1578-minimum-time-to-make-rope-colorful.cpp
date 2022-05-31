class Solution {
public:
    int minCost(string colors, vector<int>& arr) 
    {
        int n=arr.size() , ans=0;
        for(int i=0; i<n-1; i++)
        {
            int sum=0,maxi=0;
            while(i+1<n and colors[i]==colors[i+1])
                sum+=arr[i] , maxi = max(maxi,arr[i]) , i++;
            
            sum+=arr[i];
            maxi=max(maxi,arr[i]);
            
            ans+=(sum-maxi);
        }
        return ans;
    }
};