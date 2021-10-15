class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int temp=arr[i-1][j];
                arr[i-1][j]=INT_MAX;
                arr[i][j]+=*min_element(arr[i-1].begin(),arr[i-1].end());
                arr[i-1][j]=temp;
            }
        }
        
        return *min_element(arr[n-1].begin(),arr[n-1].end());
    }
};