class Solution {
public:
    //This ques is same as  : Count number of subarrays with exactly k number of ones in it
    int numSubarraysWithSum(vector<int>& arr, int k) 
    {
        //Let , number of subarrays with atmost k no. of ones = count(arr,k);
        //Count number of subarrays with exactly k number of ones in it = count(arr,k) - count(arr,k-1);
        
        int ans=k>0 ? count(arr,k)-count(arr,k-1) : count(arr,k);
        return ans;
    }
    int count(vector<int>&a , int k)
    {
        int i=0,cursum=0 , res=0 , n=a.size();
        for(int j=0;j<n;j++)
        {
           cursum+=a[j];
           while(i<n && cursum>k)
           {
               cursum-=a[i++];
           }
           res+=(j-i+1);
        }
        return res;
    }
};