//Refer Hint 1 and Hint 2
class Solution {
public:
    int minimumTime(string s) 
    {
        int n=s.size();
        
        if(n==1){
            return s[0]=='0' ? 0 : 1;
        }
        
        string str(n+1,'0');
        for(int i=0; i<n; i++)
            str[i+1]=s[i];
        
        /*for(int i=1; i<=n; i++)
            cout<<str[i];
        cout<<endl;*/
        
        vector<int>withoutFirst(n+1) , onlyFirst(n+1);
        withoutFirst[n] = str[n]=='1' ? 1 : 0; 
        
        for(int i=n-1; i>=1; i--)
        {
            if(str[i]=='0')
                withoutFirst[i]=withoutFirst[i+1];
            else
                withoutFirst[i]=min(n+1-i , 2+withoutFirst[i+1]);
        }
        
        onlyFirst[1] = str[1]=='1' ? 1 : 0;
        for(int i=2; i<=n; i++)
        {
            if(str[i]=='0')
                onlyFirst[i]=onlyFirst[i-1];
            else
                onlyFirst[i]=i;
        }
        
        /*for(int i=1; i<=n; i++)
            cout<<withoutFirst[i]<<" ";
        cout<<endl;
        for(int i=1; i<=n; i++)
            cout<<onlyFirst[i]<<" ";
        cout<<endl;*/
        
        int ans=INT_MAX;
        for(int i=1; i<=n-1; i++)
        {
            ans=min(ans , onlyFirst[i]+withoutFirst[i+1]);
        }
        
        return ans;
        
    }
};