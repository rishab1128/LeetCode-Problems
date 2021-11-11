class Solution {
public:
    int count(vector<int>&arr , int k)
    {
        int n=arr.size() , ans=0 , cnt=0;
        int left=0 , right=0;
        while(right<n)
        {
            if(arr[right]%2)
                cnt++;
            while(cnt>k)
            {
                if(arr[left]%2)
                    cnt--;
                left++;
            }
            ans+=right-left+1;
            right++;
        }
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& arr, int k) 
    {
        int ans=count(arr,k)-count(arr,k-1);
        //cout<<count(arr,k)<<" "<<count(arr,k-1)<<endl;
        return ans;
    }
};