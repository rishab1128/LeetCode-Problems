class Solution {
public:
    int trap(vector<int>& arr) 
    {
        int n = arr.size();
        int leftMax = 0 , rightMax = 0;
        int i = 0 , j = n-1 , ans = 0;
        while(i<=j)
        {
            if(arr[i]<=arr[j])
            {
                if(arr[i]>=leftMax)
                    leftMax = arr[i];
                else
                    ans+=leftMax-arr[i];
                i++;
            }
            else
            {
                if(arr[j]>=rightMax)
                    rightMax = arr[j];
                else
                    ans+=rightMax-arr[j];
                j--;
            }
        }
        
        return ans;
        
    }
};