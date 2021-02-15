using ll=long long;
class Solution {
public:
    int maxProduct(vector<int>& a) 
    {
        ll n=a.size();
        ll max_ending_here=1,min_ending_here=1,flag=0,ans=0,ct=0;
        if(n==1)
            return a[0];
        for(int i=0; i<n-1; i++)
        {
            if(a[i]!=0&&a[i+1]!=0)
            {
                flag=1;
                break;
            }
            if(a[i]>0||a[i+1]>0)
                ct++;
        }
        if(!flag&&!ct)
            return 0;
        for(int i=0; i<n; i++)
        {
            if(a[i]==0)
            {
                max_ending_here=1;
                min_ending_here=1;
            }
            else if(a[i]<0)
            {
                ll tmp=max_ending_here;
                max_ending_here=max((ll)1,min_ending_here*a[i]);
                min_ending_here=tmp*a[i];
                ans=max(ans,max_ending_here);
            }
            else
            {
                max_ending_here=max_ending_here*a[i];
                min_ending_here=min((ll)1,min_ending_here*a[i]);
                ans=max(ans,max_ending_here);
            }
        }
        return ans;
        
    }
};