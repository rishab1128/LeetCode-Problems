class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) 
    {
        int n=mat.size() ,  m=mat[0].size();
        int i=0,j=m-1;
        while(i<n and j>=0){
            if(mat[i][j]==target)
                return true;
            else if(i<n and mat[i][j]<target)
                i++;
            else if(j>=0 and mat[i][j]>target)
                j--;
        }
        return false;
        
    }
};