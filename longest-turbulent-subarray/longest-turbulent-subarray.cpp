class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) 
    {
        int n=arr.size();
        int ans=1;
        for(int i=0; i<n; i++)
        {
            if(i%2==0)
            {
                if(i+1<n and arr[i]>arr[i+1])
                {
                    int ct=1;
                    while(i<n)
                    {
                        if(i+1<n and i%2==0 and arr[i]>arr[i+1])
                            i++;
                        else if(i+1<n and i%2==1 and arr[i]<arr[i+1])
                            i++;
                        else
                            break;
                        ct++;
                    }
                    ans=max(ans,ct);
                    if(i<n)
                        i--;
                }
                else if(i+1<n and arr[i]<arr[i+1])
                {
                    int ct=1;
                    while(i<n)
                    {
                        if(i+1<n and i%2==0 and arr[i]<arr[i+1])
                            i++;
                        else if(i+1<n and i%2==1 and arr[i]>arr[i+1])
                            i++;
                        else
                            break;
                        ct++;
                    }
                    ans=max(ans,ct);
                    if(i<n)
                        i--;
                }
            }
            
            else
            {
                if(i+1<n and arr[i]>arr[i+1])
                {
                    int ct=1;
                    while(i<n)
                    {
                        if(i+1<n and i%2==1 and arr[i]>arr[i+1])
                            i++;
                        else if(i+1<n and i%2==0 and arr[i]<arr[i+1])
                            i++;
                        else
                            break;
                        ct++;
                    }
                    ans=max(ans,ct);
                    if(i<n)
                        i--;
                }
                else if(i+1<n and arr[i]<arr[i+1])
                {
                    int ct=1;
                    while(i<n)
                    {
                        if(i+1<n and i%2==1 and arr[i]<arr[i+1])
                            i++;
                        else if(i+1<n and i%2==0 and arr[i]>arr[i+1])
                            i++;
                        else
                            break;
                        ct++;
                    }
                    ans=max(ans,ct);
                    if(i<n)
                        i--;
                }
            }
            
        }
        
        return ans;
        
    }
};