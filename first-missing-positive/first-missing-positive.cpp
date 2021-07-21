class Solution {
public:
    //Time : O(N)
    //Space : O(1)
    //Refer : https://leetcode.com/problems/first-missing-positive/discuss/17214/Java-simple-solution-with-documentation
    //Short explain : In case, someone don't understand the solution, here it is in very simple words - once all numbers are made positive, if any number is found in range [1,N] then attach -ve sign to the corresponding index. So for 1, 0th element becomes -ve, for 2 it is 1st considering 0 based index. That's all
    int firstMissingPositive(vector<int>& arr) 
    {
       int n=arr.size();
        for(int i=0; i<n; i++)
        {
            if(arr[i]<=0)
                arr[i]=n+1;
        }
        for(int i=0; i<n; i++)
        {
            if(abs(arr[i])<=n)
            {
                int pos=abs(arr[i])-1;
                if(arr[pos]>0)
                    arr[pos]*=-1;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(arr[i]>0)
                return i+1;
        }
        return n+1;
    }
};
