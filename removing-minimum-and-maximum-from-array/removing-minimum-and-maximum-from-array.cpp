class Solution {
public:
    int minimumDeletions(vector<int>& arr) 
    {
        int idx1=-1,idx2=-1 , n=arr.size() , maxi=INT_MIN , mini=INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(arr[i]>maxi)
            {
                maxi=arr[i];
                idx1=i;
            }
            if(arr[i]<mini)
            {
                mini=arr[i];
                idx2=i;
            }
        }
        //Removing both from left side of the array
        int minIdx=min(idx1,idx2) , maxIdx=max(idx1,idx2);
        int op1=maxIdx+1;
        
        //Removing both from right side of the array
        int op2=n-minIdx;
        
        //Removing minIdx from left side and maxIdx from right side
        int op3=(minIdx+1)+(n-maxIdx);
        
        return min({op1,op2,op3});
    }
};