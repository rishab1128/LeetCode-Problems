class Solution {
public:
    string decodeCiphertext(string str, int rows) 
    {
        if(str.size()==0)
            return "";
        
        int total=str.size();
        int cols=total/rows;
        
        vector<vector<char>>arr(rows,vector<char>(cols));
        
        int pos=0;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                arr[i][j]=str[pos];
                pos++;
            }
        }
        
        string ans="";
        for(int j=0; j<cols; j++)
        {
            int x=0,y=j;
            while(x<rows and y<cols)
            {
                ans+=arr[x][y];
                x++;
                y++;
            }
        }
        
        int i=ans.size()-1;
        while(!isalpha(ans[i]))
        {
            ans.pop_back();
            i--;
        }
        
        return ans;
        
    }
};