class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) 
    {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        for(int i=0; i<n-2; i++)
        {
            if(i==0 || arr[i]!=arr[i-1])
            {
                int left = i+1 , right = n-1 , target = 0-arr[i];
                while(left<right)
                {
                    if(arr[left]+arr[right]==target)
                    {
                        ans.push_back({arr[i],arr[left],arr[right]});
                    
                        while(left+1<n and arr[left]==arr[left+1])
                            left++;
                        while(right-1>=0 and arr[right]==arr[right-1])
                            right--;
                    
                        left++;
                        right--;
                    }
                    else if(arr[left]+arr[right]<target)
                        left++;
                    else
                        right--;
                }
            }
        }
        
        return ans;
        
    }
};