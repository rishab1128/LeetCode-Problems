class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int m) 
    {
        int n=arr.size();
        int tot=0,ct=0;
        if(n==1&&arr[0]==0)
            return true;
        for(int i=0; i<n; i++)
        {
            if(i<n-1&&arr[i]==1&&arr[i+1]==0)
            {
                int j=i+1;
                while(j<n&&arr[j]==0)ct++,j++;
                if(j<n&&arr[j]==1&&ct%2)
                    tot+=(ct/2);
                else if(j<n&&arr[j]==1&&ct%2==0)
                    tot+=(ct/2)-1;
                else if(j==n)
                    tot+=(ct/2);
                ct=0;
                i=j-1;
            }
            else if(i<n-1&&arr[i]==0&&arr[i+1]==0)
            {
                int j=i;
                while(j<n&&arr[j]==0)ct++,j++;
                if(j<n&&arr[j]==1)
                    tot+=(ct/2);
                else if(j==n)
                    tot+=(ct/2)+(ct%2);
                ct=0;
                i=j-1;
            }
        }
        //cout<<tot<<endl;
        if(tot>=m)
            return true;
        else
            return false;
    }
};