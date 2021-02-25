class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cout.tie(NULL);
        cin.tie(NULL);
    }
    int largestRectangleArea(vector<int>& hts) 
    {
        //Using only dp and no stack
        int n=hts.size();
        int maxi=0;
        int left[n],right[n];
        left[0]=-1,right[n-1]=n;
        for(int i=1; i<n; i++)
        {
            int j=i-1;
            while(j>=0&&hts[j]>=hts[i])
            {
                j=left[j];
            }
            left[i]=j;
        }
        for(int i=n-2; i>=0; i--)
        {
            int j=i+1;
            while(j<n&&hts[j]>=hts[i])
            {
                j=right[j];
            }
            right[i]=j;
        }
        for(int i=0; i<n; i++)
        {
            maxi=max(maxi,hts[i]*(right[i]-left[i]-1));
        }
        return maxi;
    }
};