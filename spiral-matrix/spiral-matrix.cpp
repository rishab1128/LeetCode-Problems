class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) 
    {
        int firstRow=0 , lastRow=mat.size()-1 , firstCol=0 , lastCol=mat[0].size()-1;
        vector<int>ans;
        vector<vector<int>>vis(lastRow+1,vector<int>(lastCol+1,0));
        while(firstRow<=lastRow and firstCol<=lastCol)
        {
            //Push first row
            for(int j=firstCol; j<=lastCol; j++)
            {
                if(!vis[firstRow][j]){
                    ans.push_back(mat[firstRow][j]);
                    vis[firstRow][j]=1;
                }
                
            }
                
            
            //Push last col (excluding the intersection element of firstRow and lastCol )
            for(int i=firstRow+1; i<=lastRow; i++)
            {
                if(!vis[i][lastCol]){
                    ans.push_back(mat[i][lastCol]);
                    vis[i][lastCol]=1;
                }
            }
                
            
            //Push last row (excluding the intersection element of lastRow and lastCol)
            for(int j=lastCol-1; j>=0; j--)
            {
                if(!vis[lastRow][j]){
                    ans.push_back(mat[lastRow][j]);
                    vis[lastRow][j]=1;
                }
                
            }
                
            
            //Push first col (excluding the intersection element of lastRow and firstCol + firstRow and firstCol)
            for(int i=lastRow-1; i>0; i--){
                
                if(!vis[i][firstCol]){
                    ans.push_back(mat[i][firstCol]);
                    vis[i][firstCol]=1;
                }
            }
                
            
            firstRow++;
            lastRow--;
            firstCol++;
            lastCol--;
            
        }
        return ans;
        
    }
};