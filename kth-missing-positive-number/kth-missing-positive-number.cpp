class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int ans=-1;
        for(int i=1; i<=10000000; i++)
        {
            auto pos=lower_bound(arr.begin() , arr.end() , i);
            if(pos==arr.end() || *pos!=i)
            {
                k--;
                if(k==0)
                {
                    ans=i;
                    break;
                }
            }
            
        }
        return ans;
        
        
    }
};