class Solution {
public:
    int monotoneIncreasingDigits(int num) 
    {
        string s=to_string(num);
        int n=s.size();
        vector<int>arr;
        for(auto x: s)
            arr.push_back(x-'0');
        
        string tmp1=string(n,s[0]);
        int tempo1=stoi(tmp1);
        if(num<tempo1)
        {
            int f=arr[0]-1;
            int dig=n-1;
            int ans=(f*pow(10,dig));
            for(int i=1; i<n; i++)
            {
                dig--;
                ans+=(9*pow(10,dig));
            }
            return ans;
        }
        
        
        for(int i=n-2; i>=0; i--)
        {
            if(arr[i]<=arr[i+1])
                continue;
            else
            {
                arr[i]-=1;
                for(int j=i+1; j<n; j++)
                    arr[j]=9;
                
                // int j=i-1;
                // while(j>=0 and arr[j]>arr[i])
                // {
                //     arr[j]=arr[i];
                //     j--;
                // }
                // break;
            }
        }
        
        int ans=0;
        for(int i=0; i<n; i++)
        {
            //cout<<arr[i]<<" ";
            ans+=(arr[i]*pow(10,(n-i-1)));
        }
        //cout<<endl;
        return ans;  
    }
};