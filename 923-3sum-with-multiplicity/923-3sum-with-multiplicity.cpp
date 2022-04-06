const int mod=1e9+7;
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) 
    {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int ans=0;
        for(int i=0; i<n-2; i++)
        {
            int z=target-arr[i];
            int left=i+1,right=n-1;
            while(left<right)
            {
                if(arr[left]+arr[right]>z)
                    right--;
                else if(arr[left]+arr[right]<z)
                    left++;
                else if(arr[left]+arr[right]==z && arr[left]!=arr[right])
                {
                    int ct1=1,ct2=1;
                    while(arr[left]==arr[left+1] && left+1<right)
                        ct1++,left++;
                    while(arr[right]==arr[right-1] && right-1>left)
                        ct2++,right--;
                    ans+=ct1*ct2;
                    ans%=mod;
                    left++;
                    right--;
                }
                else if(arr[left]+arr[right]==z && arr[left]==arr[right])
                {
                    int m=right-left+1;
                    //We contributed M * (M-1) / 2 pairs.
                    ans+=(m*(m-1))/2;
                    ans%=mod;
                    break;
                }
            }
        }
        return ans;
        
    }
};