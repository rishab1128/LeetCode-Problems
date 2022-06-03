class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int n=arr.size() , maxi=-1 , cnt=0;
        for(int i=0; i<n; i++)
        {
            maxi=max(maxi,arr[i]);
            if(maxi==i)
                cnt++;
        }
        return cnt;
        
    }
};