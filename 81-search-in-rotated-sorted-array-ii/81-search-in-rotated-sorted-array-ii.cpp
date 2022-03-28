class Solution {
public:
    bool search(vector<int>& A, int target) 
    {
        int n=A.size();
        int lo=0, hi=n-1 ;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            
            if (A[mid] == target) return true;
        
            if (A[lo] < A[mid]) {
                if (target >= A[lo] && target < A[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            
            else if(A[lo]==A[mid])
                lo++;
            
            else {
                if (target > A[mid] && target <= A[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        
        return false;
    }
};