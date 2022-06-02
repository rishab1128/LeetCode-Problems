class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) 
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> tm(m, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                tm[j][i] = matrix[i][j];
            }
        }
        return tm;
        
    }
};