using ll = long long;
class Solution {
public:
    int maximumsSplicedArray(vector<int>& arr1, vector<int>& arr2) 
    {
        int n = arr1.size();
        
        ll sum1 = accumulate(arr1.begin(),arr1.end(),0l);
        ll sum2 = accumulate(arr2.begin(),arr2.end(),0l);
        
        ll diff1 = 0, diff2 = 0, ans = 0;
         
        for(int i=0; i<n; i++)
        {
            diff1 += arr2[i]-arr1[i];
            diff2 += arr1[i]-arr2[i];
            
            ans = max({ans , sum1+diff1 , sum2+diff2});
            
            if(diff1<0)
                diff1 = 0;
            if(diff2<0)
                diff2 = 0;
        }
        
        return ans;
        
    }
};