class Solution {
public:
    bool check(vector<int>&arr, int k, int h)
    {
        int sum=0;
        for(auto x: arr)
        {
            double tim=((double)x)/k;
            int add=ceil(tim);
            sum+=add;
        }
        return sum<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        sort(piles.begin() , piles.end());
        int n=piles.size();
        int low=1, high=piles[n-1] , ans=low;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(piles,mid,h))
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};