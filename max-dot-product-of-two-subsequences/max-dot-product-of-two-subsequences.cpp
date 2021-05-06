class Solution {
public:
    int dp[501][501];
    int func(vector<int>&nums1 , vector<int>&nums2 , int i , int j)
    {
        if(i>=nums1.size() || j>=nums2.size())
            return 0;
        if(dp[i][j]!=0)
            return dp[i][j];
        int op1=nums1[i]*nums2[j]+func(nums1,nums2,i+1,j+1);
        int op2=func(nums1,nums2,i,j+1);
        int op3=func(nums1,nums2,i+1,j);
        return dp[i][j]=max({op1,op2,op3});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        memset(dp,0,sizeof(dp));
        int n=nums1.size() , m=nums2.size();
        vector<int>a,b;
        a=nums1;
        b=nums2;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a[n-1]<0 and b[0]>0)
        {
            return a[n-1]*b[0];
        }
        else if(a[0]>0 and b[n-1]<0)
        {
            return a[0]*b[n-1];
        }
        return func(nums1 , nums2 , 0 , 0);
    }
};