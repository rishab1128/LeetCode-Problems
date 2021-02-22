class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    vector<int> sumZero(int n) 
    {
        vector<int>ans(n,0);
        int x1=-n/2,x2=n/2,i=0,j=n-1;
        while(i<j)
        {
            ans[i]=x1;
            ans[j]=x2;
            i++;
            j--;
            x1++;
            x2--;
        }
        return ans;
    }
};