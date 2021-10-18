class Solution {
public:
    int M,N;
    bool check(int mid , int k , bool&flag)
    {
        int cnt=0;
        
        for(int i=1; i<=min(M,mid); i++)
        {
            if(mid%i==0)
            {
                int quo=mid/i;
                if(quo<=N)
                    flag=true;
            }
            cnt+=min(mid/i,N);
        }
        
        return cnt>=k;
    
    }
    
    int findKthNumber(int m, int n, int k) 
    {
        M=m,N=n;
        int low=1, high=m*n , ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            bool flag=false;
            if(check(mid,k,flag))
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