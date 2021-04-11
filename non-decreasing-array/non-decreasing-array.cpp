class Solution {
public:
    bool checkPossibility(vector<int>& arr) 
    {
        int n=arr.size() , f=1;
        
        for(int i=0; i<n-2; i++)
        {
            if(arr[i]<=arr[i+1])
                continue;
            else
            {
                f=0;
                break;
            }
        }
        if(f)
            return true;
        
        f=1;
        for(int i=1; i<n-1; i++)
        {
            if(arr[i]<=arr[i+1])
                continue;
            else
            {
                f=0;
                break;
            }
        }
        if(f)
            return true;
        
        int last=-1;
        for(int i=0; i<n-1; i++)
        {
            if(arr[i]<=arr[i+1])
                continue;
            else
            {
                last=i+1;
                break;
            }
        }
        if(last!=-1)
        {
            if(arr[last+1]>=arr[last-1])
            {
                int f=1;
                for(int i=last+1; i<n-1; i++)
                {
                    if(arr[i]<=arr[i+1])
                        continue;
                    else
                    {
                        f=0;
                        break;
                    }
                }
                if(f)
                    return true;
            }
        }
        last-=1;
        if(last>0)
        {
            if(arr[last+1]>=arr[last-1])
            {
                int f=1;
                for(int i=last+1; i<n-1; i++)
                {
                    if(arr[i]<=arr[i+1])
                        continue;
                    else
                    {
                        f=0;
                        break;
                    }
                }
                if(f)
                    return true;
            }
        }
        return false;
        
    }
};