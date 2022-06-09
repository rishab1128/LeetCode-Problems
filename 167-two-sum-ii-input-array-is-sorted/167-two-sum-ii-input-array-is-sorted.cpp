class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) 
    {
        int n  = arr.size();
        int i = 0 , j = n-1;
        vector<int>ans;
        while(i<j)
        {
            if(arr[i]+arr[j]>target)
                j--;
            else if(arr[i]+arr[j]<target)
                i++;
            else
            {
                ans = {i+1,j+1};
                break;
            }
        }
        return ans;
        
    }
};