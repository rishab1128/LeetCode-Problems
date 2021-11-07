class Solution {
public:
    bool check(int k, int n, vector<int>&qty)
    {
        int m=qty.size() , numOfPeople=0;
        for(int i=0; i<m; i++)
        {
            int x=qty[i];
            if(i==m-1)
                x-=k;
            numOfPeople+=((x/k)+(1?x%k>0:0));
        }
        //cout<<numOfPeople<<" "<<n-1<<endl;
        return numOfPeople<=n-1;

    }

    int minimizedMaximum(int n, vector<int>& qty) 
    {
        int low=1,high=*max_element(qty.begin(),qty.end()),ans=high , m=qty.size();
        if(n==m)
            return ans;
        sort(qty.begin(),qty.end());
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(check(mid,n,qty))
            {
                ans=mid;
                high=mid;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};