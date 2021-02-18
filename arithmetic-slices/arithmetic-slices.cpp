class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    bool check(vector<int>& A, int i, int j, int&diff)
    {
        if(A[i+1]-A[i]==A[j]-A[i+1])
        {
            diff=A[i+1]-A[i];
            return true;
        }
        return false;
    }
    
    int numberOfArithmeticSlices(vector<int>& A) 
    {
        int n=A.size();
        if(n<=2)
            return 0;
        int i=0,j=2;
        vector<int>ans;
        while(j-i+1>=3&&j<n)
        {
            int diff=0;
            if(i<j&&j<n&&check(A,i,j,diff))
            {
                while(j+1<n&&A[j+1]-A[j]==diff)
                    j++;
                ans.push_back(j-i+1);
                i=j+1;
                j=i+2;
                if(j>=n)
                    break;
            }
            else if(i<j&&j<n&&check(A,i,j,diff)==false)
            {
                i++;
                j++;
            }
        }
        
        int res=0;
        for(auto x: ans)
        {
            int n=x-2;
            res+=(n*(n+1)/2);
        }
        return res;
    }

};