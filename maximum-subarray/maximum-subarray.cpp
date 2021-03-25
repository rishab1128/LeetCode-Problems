class Solution {
public:
    int maxSubArray(vector<int>& arr) 
    {
        int curr=0,best=0,flag=0,maxi=INT_MIN;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]>0)
                flag=1;
            if(curr>=0)
                curr+=arr[i];
            if(curr<0)
                curr=0;
            maxi=max(maxi,arr[i]);
            best=max(best,curr);
        }
        if(!flag)
            return maxi;
        return best;
        
        
    }
};