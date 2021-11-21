class Solution {
public:
    int maxDistance(vector<int>& arr) 
    {
        int n=arr.size() , ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(arr[i]!=arr[j])
                    ans=max(ans,abs(i-j));
            }
        }
        return ans;
    }
};