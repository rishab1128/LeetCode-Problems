class Solution {
public:
    //Binary Search Solution 
    //TC: O(log(n1+n2)) SC : O(1)
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) 
    {
        if(arr2.size() < arr1.size()) return findMedianSortedArrays(arr2, arr1);
        int n1=arr1.size(),n2=arr2.size();
        int low=0 , high=n1 ;
        //cout<<low<<" "<<high<<endl;
        while(low<=high)
        {
            int cut1=low+((high-low)/2);
            int cut2=(n1+n2+1)/2-cut1;
            
            //cout<<cut1<<" "<<cut2<<endl;

            int l1 =( cut1==0 ?  INT_MIN : arr1[cut1-1] );
            int l2 =( cut2==0 ?  INT_MIN : arr2[cut2-1] );
            
            int r1 =( cut1>=n1 ? INT_MAX : arr1[cut1] );
            int r2 =( cut2>=n2 ? INT_MAX : arr2[cut2] );
            
            //cout<<l1<<" "<<l2<<" "<<r1<<" "<<r2;

            if(l1<=r2 and l2<=r1)
            {
                if((n1+n2)%2==0)
                    return (max(l1,l2)+min(r1,r2))/2.0;
                else
                    return max(l1,l2);
            }
            else if(l1>r2)
                high=cut1-1;
            else
                low=cut1+1;
        }
        return 0.0;
    }
};