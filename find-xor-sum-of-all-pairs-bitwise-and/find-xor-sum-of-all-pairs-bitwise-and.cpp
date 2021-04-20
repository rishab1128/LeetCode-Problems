class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) 
    {
        int n=arr1.size(),m=arr2.size();
        int x=0;
        for(int i=0; i<m; i++)
            x^=arr2[i];
        cout<<x<<endl;
        int z=0;
        for(int i=0; i<n; i++)
            z^=(arr1[i]&x);
        cout<<z<<endl;
        
        return z;
        
    }
};