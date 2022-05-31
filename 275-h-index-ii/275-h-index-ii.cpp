class Solution {
public:
    int hIndex(vector<int>& arr) 
    {
        int n=arr.size();
        int low=0 , ans=0, high=n-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int ele = arr[mid];
            int behind = n-mid;
            if(ele==behind)
            {
                ans=ele;
                break;
            }
            else if(ele<behind)
                low=mid+1;
            else if(ele>behind)
            {
                ans=max(ans,behind);
                high=mid-1;
            }
                
        }
        return ans;
    
    }
};