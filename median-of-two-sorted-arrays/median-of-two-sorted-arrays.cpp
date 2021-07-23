class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) 
    {
        int m=A.size() , n=B.size();
        int i=0,j=0,ct=0;
        double res=0;
        while(i<m and j<n)
        {
            if(A[i]<=B[j])
            {
                ct++;
                if((m+n)%2 && ct==(m+n+1)/2)
                {
                    double ans=(double)A[i];
                    return ans;
                }
                else if((m+n)%2==0 && (ct==(m+n)/2 || ct==(m+n)/2+1))
                    res+=(double)A[i];
                i++;
            }
            else
            {
                ct++;
                if((m+n)%2 && ct==(m+n+1)/2)
                {
                    double ans=(double)B[j];
                    return ans;
                }
                else if((m+n)%2==0 && (ct==(m+n)/2 || ct==(m+n)/2+1))
                    res+=(double)B[j];
                j++;
            }
        }
        while(i<m)
        {
            ct++;
            if((m+n)%2 && ct==(m+n+1)/2)
            {
                double ans=(double)A[i];
                return ans;
            }
            else if((m+n)%2==0 && (ct==(m+n)/2 || ct==(m+n)/2+1))
                res+=(double)A[i];
            i++;
        }
        while(j<n)
        {
            ct++;
            if((m+n)%2 && ct==(m+n+1)/2)
            {
                double ans=(double)B[j];
                return ans;
            }
            else if((m+n)%2==0 && (ct==(m+n)/2 || ct==(m+n)/2+1))
                res+=(double)B[j];
            j++;
        }

        return res/2;
    }
};