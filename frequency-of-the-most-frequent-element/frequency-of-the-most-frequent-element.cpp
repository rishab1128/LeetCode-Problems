class Solution {
public:
    //O(N) + O(N*log(N))-> Sorting + Sliding Window Approach
    int maxFrequency(vector<int>& arr, int k) 
    {
        sort(arr.rbegin(),arr.rend());
        long long sum=0;
        int left=0, right=0, n=arr.size() , ans=1;
        while(right<n)
        {
            sum+=arr[right];
            while((long long)arr[left]*(right-left+1)-sum>k)
            {
                sum-=arr[left];
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};