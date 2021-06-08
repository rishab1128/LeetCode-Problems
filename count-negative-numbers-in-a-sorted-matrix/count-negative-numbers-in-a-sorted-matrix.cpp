class Solution {
public:
    int countNegatives(vector<vector<int>>& mat) 
    {
        int n=mat.size(),ans=0;
        for(int i=0; i<n; i++)
        {
            sort(mat[i].begin(),mat[i].end());
            int pos=lower_bound(mat[i].begin(),mat[i].end(),0)-mat[i].begin()-1;
            ans+=(pos+1);
        }
        return ans;
        
    }
};