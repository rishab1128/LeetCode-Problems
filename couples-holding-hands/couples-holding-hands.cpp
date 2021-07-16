class Solution {
public:
    int minSwapsCouples(vector<int>& row) 
    {
        map<int,int>mp;
        int sz=row.size() ,j=1;
        for(int i=0; i<sz; i+=2)
        {
            mp[i]=j;
            mp[i+1]=j;
            j++;
        }
        
        vector<int>arr(sz);
        for(int i=0; i<sz; i++)
        {
            arr[i]=mp[row[i]];
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        
        int ans=0;
        for(int i=0; i<sz-1; i+=2)
        {
            if(arr[i]!=arr[i+1])
            {
                int pos=-1;
                for(int j=i+2; j<sz; j++)
                {
                    if(arr[i]==arr[j])
                    {
                        pos=j;
                        break;
                    }
                }
                swap(arr[i+1],arr[pos]);
                ans++;
            }
        }
        
        return ans;
        
        
        
        
    }
};