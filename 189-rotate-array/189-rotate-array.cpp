class Solution {
public:
    void rotate(vector<int>& arr, int k) 
    {
        int n=arr.size();
        k=k%n;
        if(k==0)
            return;
        reverse(arr.begin(),arr.end());
        reverse(arr.begin(),arr.begin()+k);
        reverse(arr.begin()+k,arr.end());
        
        return;
        
    }
};