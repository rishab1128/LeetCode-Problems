class Solution {
public:
    bool checkOneRow(vector<int>arr){
        int n = arr.size(), ct = 0;
        for(auto x: arr){
            if(x==1)
                ct++;
        }
        return ct==n;
    }
    
    
    bool checkZeroRow(vector<int>arr){
        int n = arr.size(), ct = 0;
        for(auto x: arr){
            if(x==0)
                ct++;
        }
        return ct==n;
    }
    
    void toggleCol(vector<vector<int>>& arr, int j)
    {
        int n = arr.size();
        for(int i=0; i<n; i++)
            arr[i][j]^=1;
    }
    
    bool removeOnes(vector<vector<int>>& arr) {
        //Brute Force : O(n*m)
        
        //Claim : 
        //After making the first row all ones 
        //All the remaining rows should be either ZeroRow(row with all o's) or OneRow(row with all 1's)
        
        int n = arr.size() , m = arr[0].size();
        
        if(!checkZeroRow(arr[0]))
        {
            for(int j=0; j<m; j++)
            {
                if(!arr[0][j])
                    toggleCol(arr,j);
            }
        }
        
        for(int i=1; i<n; i++)
        {
            if(!checkZeroRow(arr[i]) and !checkOneRow(arr[i]))
                return false;
        }
        
        return true;
        
        
    }
};