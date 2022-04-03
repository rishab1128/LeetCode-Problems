class Solution {
public:
    void nextPermutation(vector<int>& arr) 
    {
        int n=arr.size() , pos=-1;
        for(int i=n-1; i>0; i--)
        {
            if(arr[i]<=arr[i-1])
                continue;
            else
            {
                pos=i;
                break;
            }
        }
        
        if(pos==-1)
        {
            sort(arr.begin() , arr.end());
            return;
        }
        int zs=arr[pos-1] , res=INT_MAX , pos2=-1;
        for(int i=pos; i<n; i++)
        {
            if(arr[i]>zs and arr[i]<res)
            {
                res=arr[i];
                pos2=i;
            }
        }
        swap(arr[pos-1] , arr[pos2]);
        sort(arr.begin()+pos,arr.end());
        return;
    }
};