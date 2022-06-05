class Solution {
public:
    int partitionArray(vector<int>& arr, int k) 
    {
        sort(arr.begin(),arr.end());
        int n = arr.size() , i = 0 , cnt = 0;
        while(i<n)
        {
            int idx = upper_bound(arr.begin()+i,arr.end(),arr[i]+k)-arr.begin();
            idx--;
            if(idx!=n)
            {
                i=idx+1;
                cnt++;
            }
            else
            {
                cnt++;
                break;
            }
        }
        return cnt;
        
    }
};