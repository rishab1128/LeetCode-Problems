class Solution {
public:
    //Using Binary Search
    int m,n;
    bool check(vector<vector<int>>&mat , int midVal , int k , bool&flag)
    {
        int cnt=0;
        int r=0,c=n-1;
        while(r<m and c>=0)
        {
            if(mat[r][c]==midVal)
            {
                flag=true;
                cnt+=(c+1);
                r++;
            }
            else if(mat[r][c]<midVal)
            {
                cnt+=(c+1);
                r++;
            }
            else if(mat[r][c]>midVal)
                c--;
        }
        
        return cnt>=k;
    }
    
    int kthSmallest(vector<vector<int>>& mat, int k) 
    {
        m=mat.size() , n=mat[0].size();
        int low=mat[0][0] , high=mat[m-1][n-1] , ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            bool flag=false;
            if(check(mat, mid , k , flag))
            {
                if(flag)
                    ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};