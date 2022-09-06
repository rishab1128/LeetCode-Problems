class Solution {
public:
    
    void add(int x, vector<int>&freq)
    {
        for(int i=0; i<32; i++)
        {
            int num = (1<<i);
            if(x&num)
                freq[i]++;
        }
    }
    
    void remove(int x, vector<int>&freq)
    {
        for(int i=0; i<32; i++)
        {
            int num = (1<<i);
            if(x&num)
                freq[i]--;
        }
    }
    
    bool canAdd(int x, vector<int>&freq)
    {
        for(int i=0; i<32; i++)
        {
            int num = (1<<i);
            if(x&num and freq[i]==1)
                return false;
        }
        return true;
    }
    
    bool notValid(vector<int>&freq)
    {
        for(int i=0; i<32; i++)
        {
            if(freq[i]>1)
                return true;
        }
        return false;
    }
    
    int longestNiceSubarray(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int>freq(32,0);
        add(arr[0],freq);
        int ans = 1 , j = 0 , i;
        for(i=1; i<n; i++)
        {
            if(canAdd(arr[i],freq))
                add(arr[i],freq);
            else
            {
                ans = max(ans,i-j);
                // cout<<j<<" "<<i<<" "<<ans<<endl;
                add(arr[i],freq);
                while(notValid(freq))
                {
                    remove(arr[j],freq);
                    j++;
                }
            }
        }
        
        ans = max(ans,i-j);
        
        return ans;
    }
};