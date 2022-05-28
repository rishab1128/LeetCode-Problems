class Solution {
public:
    int maximumTop(vector<int>& arr, int k) 
    {
        int n = arr.size();
        
        if(n==1 and k%2)
            return -1;
        
        if(k==0)
            return arr[0];
        
        int maxEle = *max_element(arr.begin() , arr.end());
        if(k>n)
            return maxEle;
        
        int maxi=INT_MIN;
        for(int i=0; i<k-1; i++)
            maxi=max(maxi,arr[i]);
        
        int ans = k<n ? max(maxi , arr[k]) : maxi;
        return ans;
    }
};