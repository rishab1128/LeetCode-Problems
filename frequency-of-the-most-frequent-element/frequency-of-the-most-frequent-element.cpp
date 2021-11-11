class Solution {
public:
    //O(N*log(N)) approach -> Prefis Sum+Binary Search
    
    // Count frequency of `arr[idx]` if we make other elements equal to `arr[idx]`
    int count(vector<long long>&pref , vector<int>&arr, int idx, int k)
    {
        int left=0 , right=idx , pos=idx;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            long long sum= mid-1>=0 ? pref[idx]-pref[mid-1] : pref[idx] ; // get sum of(arr[mid], arr[mid + 1]...arr[idx - 1])
            int windowLen=idx-mid+1;
            long long total=(long long)arr[idx]*(long long)windowLen-sum;
            if(total<=k) //Found an answer -> Try to find a better answer in the left side
            {
                pos=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        int freq=idx-pos+1;
        return freq;
    }
    
    int maxFrequency(vector<int>& arr, int k) 
    {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<long long>pref(n);
        pref[0]=arr[0];
        for(int i=1; i<n; i++)
            pref[i]=pref[i-1]+arr[i];
        
        int ans=0;
        for(int i=0; i<n; i++)
            ans=max(ans, count(pref,arr,i,k));
        
        return ans;
    }
    
    
};