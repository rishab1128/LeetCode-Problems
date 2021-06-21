class Solution {
public:
    vector<vector<int>> generate(int n) 
    {
        vector<vector<int>>ans(n);
        ans[0]={1};
        if(n>1)
            ans[1]={1,1};
        if(n>2)
        {
            for(int i=2; i<n; i++)
            {
                vector<int>tmp(i+1);
                tmp[0]=1;
                tmp[i]=1;
                int k=0;
                for(int j=1; j<tmp.size()-1; j++)
                {
                    //cout<<ans[i-1][k]<<" "<<ans[i-1][k+1]<<endl;
                    tmp[j]=ans[i-1][k]+ans[i-1][k+1];
                    k++;
                }
                ans[i]=tmp;
            }
        }
        return ans;
        
    }
};