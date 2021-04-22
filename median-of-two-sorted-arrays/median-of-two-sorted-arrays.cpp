class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) 
    {
        int n=a.size() , m=b.size();
        if(n==0 and m==0)
            return 0.00000;
        //Assuming len(a) <= len(b) always 
        if(n>m)
        {
            swap(a,b);
            swap(n,m);
        }
        
        if(n==0 &&  m>0)
        {
            if(m%2)
                return (double)b[m/2];
            else
                return ((double)b[m/2]+b[(m/2)-1])/2;
        }
        
        int a_min=0,a_max=n;
        int len=(m+n+1)/2;
        while(a_min<=a_max)
        {
            int a_count=a_min+(a_max-a_min)/2;
            int b_count=len-a_count;
            if(a_count > 0 and a[a_count-1] > b[b_count])
                a_max=a_count-1;
            else if(a_count < n and a[a_count] < b[b_count-1])
                a_min=a_count+1;
            else
            {
                int lefti=0,righti=0;
                if(a_count==0)
                    lefti=b[b_count-1];
                else if(b_count==0)
                    lefti=a[a_count-1];
                else
                    lefti=max(a[a_count-1],b[b_count-1]);
                
                if((m+n)%2)
                    return (double)lefti;
                
                if(a_count==n)
                    righti=b[b_count];
                else if(b_count==m)
                    righti=a[a_count];
                else
                    righti=min(a[a_count],b[b_count]);
                
                return ((double)lefti+righti)/2;
                
            }
        }
        return -1;
    }
};