class Solution {
public:
    int traverse(vector<vector<int>>&arr)
    {
        int m=arr.size() , ans=0;
        for(int i=0; i<m-1; i++)
        {
            int h1=arr[i][1] , h2=arr[i+1][1];
            int d1=arr[i][0] , d2=arr[i+1][0];
            int h=h1+abs(d2-d1);
            if(h>h2)
                h=h2+(h-h2)/2;
            if(h<h2)
                arr[i+1][1]=h;
            ans=max(ans,h);
        }
        return ans;
    }
    int maxBuilding(int n, vector<vector<int>>& res) 
    {
        res.insert(res.end(),{{1,0} ,{n,n-1}});
        sort(res.begin(),res.end());
        traverse(res);
        reverse(res.begin(),res.end());
        return traverse(res);
    }
};