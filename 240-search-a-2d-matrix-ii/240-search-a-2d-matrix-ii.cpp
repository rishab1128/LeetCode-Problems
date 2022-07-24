class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        int r=0,c=n-1;
        //cout<<r<<" "<<c<<endl;
        //cout<<matrix[r][c]<<endl;
        while(c>=0&&r<m)
        {
            if(matrix[r][c]==target)
                return true;
            else if(matrix[r][c]<target)
                r++;
            else
                c--;
        }
        return false;
        
    }
};