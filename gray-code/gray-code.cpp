class Solution {
public:
    //Refer Solution for more clarity
    //Recursion based approach
    void func(int n, vector<int>&ans)
    {
        if(n==0)
        {
            ans.push_back(0);
            return;
        }
        func(n-1,ans);
        int curr_size=ans.size();
        int mask=1<<(n-1);
        for(int i=curr_size-1; i>=0; i--)
        {
            ans.push_back(mask+ans[i]);
        }
        return;
    }
    vector<int> grayCode(int n) 
    {
        vector<int>ans;
        func(n,ans);
        return ans;
    }
};