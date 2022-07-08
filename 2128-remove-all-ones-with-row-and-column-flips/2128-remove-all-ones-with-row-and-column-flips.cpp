class Solution {
public:
    bool removeOnes(vector<vector<int>>& arr) 
    {
        int n = arr.size() , m = arr[0].size();
        
        //Claim 2 : All rows should have the same pattern (some rows may require 1 flip)
        
        //00010010                           00010010
        //00010010                           00010010
        //11101101  ---> Flip this row---->  00010010
        //11101101  ---> Flip this row---->  00010010
        
        //Approach : Compare each row pattern with row[0]'s pattern if it macthes completelty then okay and if it does not matches then it should not match for all the m positions-> if no. of unmatched positions < m then return false
        
        for(int i=1; i<n; i++)
        {
            int cnt = 0;
            for(int j=0; j<m; j++)
            {
                if(arr[i][j]==arr[0][j])
                    continue;
                else
                    cnt++;
            }
            if(cnt>0 and cnt<m)
                return false;
        }
        
        return true;
        
    }
};