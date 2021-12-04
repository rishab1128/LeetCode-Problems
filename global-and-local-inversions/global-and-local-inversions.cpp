//No. of global inversions can be >= No. of local inversions
//For global inversions to be equal to local inversions , we should only have local inversions in the array
//To have only local inversions in the array A , A[i] can be only at positions A[i-1] , A[i] , A[i+1]
class Solution {
public:
   bool isIdealPermutation(vector<int>& A) {
        for (int i = 0; i < A.size(); ++i)
            if (abs(A[i] - i) > 1) return false;
        return true;
    }
};