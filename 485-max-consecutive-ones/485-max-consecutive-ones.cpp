class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) 
    {
        int n = arr.size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int j = i , cnt = 0;
            while(j<n and arr[j])
            {
                cnt++;
                j++;
            }
            ans = max(ans,cnt);
            i = j;
        }
        return ans;
        
    }
};