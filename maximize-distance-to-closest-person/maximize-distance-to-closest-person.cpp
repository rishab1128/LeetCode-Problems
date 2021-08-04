class Solution {
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        int n=seats.size();
        vector<int>arr;
        for(int i=0; i<n; i++)
        {
            if(seats[i])
                arr.push_back(i);
        }
        
        int m=arr.size();
        int res,ans=INT_MIN;
        for(int i=0; i<n; i++)
        {
            if(seats[i]==0)
            {
                int hi=upper_bound(arr.begin() ,arr.end() , i)-arr.begin();
                int lo=hi-1;
                int x1=INT_MAX,x2=INT_MAX;
                
                if(hi<m and lo>=0)
                {
                    x1=i-arr[lo];
                    x2=arr[hi]-i;
                    res=min(x1,x2);
                    //cout<<arr[hi]<<" "<<arr[lo]<<" "<<x1<<" "<<x2<<endl;
                }
                else if(hi==m)
                {
                    x1=i-arr[lo];
                    res=min(x1,x2);
                }
                else if(hi==0)
                {
                    x2=arr[hi]-i;
                    res=min(x1,x2);
                }
                
                ans=max(ans,res);                
            }
        }
        return ans;
        
    }
};