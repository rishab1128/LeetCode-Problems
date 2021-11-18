class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& arr) 
    {
        //Problem same as : 41. First Missing Positive
        int n=arr.size();
        for(int i=0; i<n; i++)
        {
            int pos=abs(arr[i])-1;
            if(arr[pos]>0)
                arr[pos]*=-1;
        }
        vector<int>ans;
        for(int i=0; i<n; i++)
        {
            if(arr[i]>0)
                ans.push_back(i+1);
        }
        return ans;
        
    }
};