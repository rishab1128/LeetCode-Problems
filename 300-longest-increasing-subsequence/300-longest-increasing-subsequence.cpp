class Solution {
public:
    int LIS(vector<int>&arr)
    {
        int size=arr.size() ;
        vector<int> seq;
        seq.push_back(arr[0]);

        for(int i=1; i<size; i++)
        {
            if(seq.back()<arr[i])
                seq.push_back(arr[i]);
            else
            {
                int index=lower_bound(seq.begin(),seq.end(),arr[i])-seq.begin();
                seq[index]=arr[i];
            }
        }

        int ans=seq.size();
        return ans;
    }
    
    int lengthOfLIS(vector<int>& nums) 
    {
        return LIS(nums);
    }
};