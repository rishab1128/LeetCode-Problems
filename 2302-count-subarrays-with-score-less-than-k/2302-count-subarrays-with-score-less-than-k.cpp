class Solution {
public:
    long long countSubarrays(vector<int>& arr, long long k) 
    {
        int n = arr.size();
        int left = 0 , right = 0 , lastRight = 0;
        long long sum = 0 ,  ans = 0;
        while(right<n)
        {
            long long tmp = (sum+arr[right])*(right-left+1);
            if(tmp<k)
            {
                sum+=arr[right];
                right++;
            }
            else
            {
                long long totalLen = right-left;
                long long totalSum = totalLen*(totalLen+1)/2;
                long long overlapLen = lastRight>left ? lastRight - left : 0;
                long long overlapSum = overlapLen*(overlapLen+1)/2;
                ans += totalSum - overlapSum;
                // cout<<ans<<endl;
                if(arr[right]>k){
                    right++;
                    left = right;
                    sum = 0;
                }
                else
                {
                    sum+=arr[right];
                    lastRight = right;
                    while(sum*(right-left+1)>=k)
                    {
                        sum-=arr[left];
                        left++;
                    }
                    right++;
                }   
            }
        }
        
        long long totalLen = right-left;
        long long totalSum = totalLen*(totalLen+1)/2;
        long long overlapLen = lastRight>left ? lastRight - left : 0;
        long long overlapSum = overlapLen*(overlapLen+1)/2;
        ans += totalSum - overlapSum;
        
        return ans;
        
    }
};