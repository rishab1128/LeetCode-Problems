class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    vector<int> minOperations(string boxes) 
    {
        int n=boxes.size();
        vector<int>ans(n,0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                ans[i]+=(int(boxes[j]-'0'))*abs(i-j);
        }
        return ans;
        
    }
};