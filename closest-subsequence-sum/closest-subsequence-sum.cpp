class Solution {
public:
    
    void fillSet(vector<int>&arr,  int idx , int sum , vector<int>&subset)
    {
        if(idx>=arr.size())
        {
            subset.push_back(sum);
            return;
        }
        fillSet(arr,idx+1,sum+arr[idx],subset);
        fillSet(arr,idx+1,sum,subset);
    }
    
    int minAbsDifference(vector<int>& arr, int goal) 
    {
        int n=arr.size();
        vector<int>half1 , half2;
        for(int i=0; i<n/2; i++)
            half1.push_back(arr[i]);
        for(int i=n/2; i<n; i++)
            half2.push_back(arr[i]);
        
        vector<int>subset1 , subset2;
        
        fillSet(half1,0,0,subset1);
        fillSet(half2,0,0,subset2);
        
        sort(subset2.begin() , subset2.end());
        int ans=INT_MAX;
        for(int i=0; i<subset1.size(); i++)
        {
            auto it=lower_bound(subset2.begin(),subset2.end(),goal-subset1[i]);
            if(it!=subset2.end())
                ans=min(ans,abs(goal-subset1[i]-(*it)));
            
            if(it!=subset2.begin())
            {
                it--;
                ans=min(ans,abs(goal-subset1[i]-(*it)));
            }
        }
        
        return ans;
        
    }
};