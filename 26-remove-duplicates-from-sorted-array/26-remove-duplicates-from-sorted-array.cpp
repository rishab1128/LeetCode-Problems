class Solution {
public:
    int removeDuplicates(vector<int>& arr) 
    {
        int n = arr.size() ,k = 1;
        for(int i=0; i<n-1; i++)
        {
            int j = i+1;
            while(j<n and arr[i]==arr[j])
                j++;
            if(j<n)
            {
                arr[k] = arr[j];
                k++;
            }
            i = j-1;
        }
        return k;
        
    }
};