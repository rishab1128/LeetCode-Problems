using ll = long long;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) 
    {
        vector<vector<int>>ans;
        sort(arr.begin() , arr.end());
        int n = arr.size();
        for(int i=0; i<n-3; i++)
        {
            for(int j=i+1; j<n-2; j++)
            {
                
                ll sum = (ll)target - (ll)(arr[i]+arr[j]);
                
                int left = j+1 , right = n-1;
                
                while(left<right)
                {
                    if(arr[left]+arr[right]==sum)
                    {
                        ans.push_back({arr[i],arr[j],arr[left],arr[right]});
                        
                        while(left+1<n and arr[left]==arr[left+1])
                            left++;
                        while(right-1>=0 and arr[right]==arr[right-1])
                            right--;
                        
                        left++;
                        right--;
                    }
                    else if(arr[left]+arr[right]<sum)
                        left++;
                    else
                        right--;
                }
                
                int k = j;
                while(k+1<n and arr[k]==arr[k+1])
                    k++;
                j = k;
            }
            
            int k = i;
            while(k+1<n and arr[k]==arr[k+1])
                k++;
            i = k;
        }
        
        return ans;
    }
};