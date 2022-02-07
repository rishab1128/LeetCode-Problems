class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& arr) 
    {
        vector<int>odd,even;
        int n=arr.size();
        for(int i=0; i<n; i++)
        {
            if(i%2)
                odd.push_back(arr[i]);
            else
                even.push_back(arr[i]);
        }
        sort(odd.rbegin(),odd.rend());
        sort(even.begin(),even.end());
        
        vector<int>ans;
        int i=0 , j=0, ct=0;
        while(ct!=n)
        {
            if(ct%2==0)
                ans.push_back(even[i++]);
            else
                ans.push_back(odd[j++]);
            ct++;
        }
        
        return ans;
            
        
    }
};