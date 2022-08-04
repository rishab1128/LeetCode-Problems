class Solution {
public:
    //Binary Search Solution 
    //TC: O(log(min(n1,n2))) SC : O(1)
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) 
    {
        if(a.size()>b.size())
            swap(a,b);
    
        int n1 = a.size() , n2 = b.size() , tot = (n1+n2+1)/2;
        int low = 0 , high = n1;
        // cout<<low<<" "<<high<<" "<<tot<<endl;
        while(low<=high)
        {
            int cut1 = low+(high-low)/2;
            int cut2 = tot-cut1;

            int l1 = cut1-1>=0 ? a[cut1-1] : INT_MIN;
            int l2 = cut2-1>=0 ? b[cut2-1] : INT_MIN;

            int r1 = cut1<n1 ? a[cut1] : INT_MAX;
            int r2 = cut2<n2 ? b[cut2] : INT_MAX;
            
            // cout<<l1<<" "<<r1<<endl;
            // cout<<l2<<" "<<r2<<endl;

            if(l1<=r2 and l2<=r1)
            {
                if((n1+n2)%2==0)
                    return (max(l1,l2)+min(r1,r2))/2.0;
                else
                    return max(l1,l2);
            }
            else if(l1>r2)
                high = cut1-1;
            else
                low = cut1+1;
        }
        return 0.0;
    }
};