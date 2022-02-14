class Solution {
public:
    int minimumOperations(vector<int>& arr) 
    {
        int n=arr.size() , ans=INT_MAX;
        unordered_map<int,int>odd,even;
        for(int i=0; i<n; i++)
        {
            if(i%2==0)
                even[arr[i]]++;
            else
                odd[arr[i]]++;
        }
        
        int eveMax=0 , eveMax2=0 , oddMax=0 , oddMax2=0;
        int maxi1=0 , maxi2=0;
        
        //EVEN INDICES
        for(auto [x,y] : even)
        {
            if(y>maxi1)
            {
                maxi1=y;
                eveMax=x;
            }
        }
        for(auto [x,y] : even)
        {
            if(y>maxi2 and y<=maxi1 and x!=eveMax) 
            {
                maxi2=y;
                eveMax2=x;
            }
        }
        
        
        //ODD INDICES
        maxi1=0 , maxi2=0;
        for(auto [x,y] : odd)
        {
            if(y>maxi1)
            {
                maxi1=y;
                oddMax=x;
            }
        }
        for(auto [x,y] : odd)
        {
            if(y>maxi2 and y<=maxi1 and x!=oddMax)
            {
                maxi2=y;
                oddMax2=x;
            }
        }
        
//         cout<<"EVEN : "<<endl;
//         cout<<eveMax<<" "<<even[eveMax]<<endl;
//         cout<<eveMax2<<" "<<even[eveMax2]<<endl<<endl;
        
//         cout<<"ODD : "<<endl;
//         cout<<oddMax<<" "<<odd[oddMax]<<endl;
//         cout<<oddMax2<<" "<<odd[oddMax2]<<endl;
        
        if(eveMax!=oddMax)
        {
            int ctEven=(n+1)/2 , ctOdd=n/2;
            ans=ctEven-even[eveMax]+ctOdd-odd[oddMax];
        }
        else
        {
            int ctEven=(n+1)/2 , ctOdd=n/2;
            int ans1=ctEven-even[eveMax]+ctOdd-odd[oddMax2];
            int ans2=ctEven-even[eveMax2]+ctOdd-odd[oddMax];
            ans=min(ans1,ans2);
        }
        
        return ans;
    }
};