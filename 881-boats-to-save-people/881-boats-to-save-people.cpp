class Solution {
public:
    int numRescueBoats(vector<int>& arr, int lt) 
    {
        sort(arr.begin() , arr.end());
        int n=arr.size();
        int i=0 , j=n-1 , ct=0;
        while(i<j)
        {
            if(arr[i]+arr[j]<=lt)
            {
                i++;
                j--;
                ct++;
            }
            else
            {
                j--;
                ct++;
            }
        }
        if(i==j)
            ct++;
        return ct;
        
    }
};