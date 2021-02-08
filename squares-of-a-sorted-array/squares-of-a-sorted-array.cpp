class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    vector<int> sortedSquares(vector<int>& nums) 
    {
        vector<int>neg,pos;
        for(int x: nums)
        {
            if(x<0)
                neg.push_back(x*-1);
            else
                pos.push_back(x);
        }
        reverse(neg.begin(),neg.end());
        int n=pos.size(),m=neg.size();
        int i=0,j=0;
        vector<int>ans;
        while(i<n&&j<m)
        {
            if(pos[i]<=neg[j])
            {
                ans.push_back(pos[i]*pos[i]);
                i++;
            }
            else
            {
                ans.push_back(neg[j]*neg[j]);
                j++;
            }
        }
        while(i<n)
        {
            ans.push_back(pos[i]*pos[i]);
            i++;
        }
        while(j<m)
        {
            ans.push_back(neg[j]*neg[j]);
            j++;
        }
        return ans;
    }
};