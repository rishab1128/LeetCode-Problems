typedef pair<int,int> pii;
class Solution {
public:
    //BS on Answer + Sliding Window and DQ for finding Min and Max of every window of size k
    bool check(vector<int>&arr , int k , int limit)
    {
        //cout<<k<<endl;
        
        int n=arr.size();
        deque<int>MaxDq,MinDq;
        
        for(int i=0; i<k-1; i++)
        {
            while(!MaxDq.empty()&&arr[MaxDq.back()]<=arr[i])
                MaxDq.pop_back();
            
            while(!MinDq.empty()&&arr[MinDq.back()]>=arr[i])
                MinDq.pop_back();
            
            MaxDq.push_back(i);
            MinDq.push_back(i);
        }
        
        for(int i=k-1; i<n; i++)
        {
            while(!MaxDq.empty()&&MaxDq.front()<=i-k)
                MaxDq.pop_front();
            
            while(!MinDq.empty()&&MinDq.front()<=i-k)
                MinDq.pop_front();
            
            while(!MaxDq.empty()&&arr[MaxDq.back()]<=arr[i])
                MaxDq.pop_back();
            
            while(!MinDq.empty()&&arr[MinDq.back()]>=arr[i])
                MinDq.pop_back();
            
            MaxDq.push_back(i);
            MinDq.push_back(i);
            
            if(arr[MaxDq.front()]-arr[MinDq.front()]<=limit)
                return true;
        }
        return false;
    }
    
    int longestSubarray(vector<int>& arr, int limit) 
    {
        int low=1, high=arr.size();
        int ans=1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(arr,mid,limit))
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
        
    }
};