class Solution {
public:
    bool canConvertString(string s, string t, int k) 
    {
        if(s.size()!=t.size())
            return false;
        
        int n=s.size();
        vector<long long>diff(n);
        for(int i=0; i<n; i++)
        {
            int x=s[i]-'a',y=t[i]-'a';
            if(x<=y)
                diff[i]=y-x;
            else
                diff[i]=('z'-s[i])+(t[i]-'a'+1);
        }
        

        
        
            
        
        /*for(auto x: diff)
            cout<<x<<" ";
        cout<<endl;*/
        
        sort(diff.begin(),diff.end());
        
        
        
        for(int i=0; i<n; i++)
        {
            if(diff[i]==0)
                continue;
            int ct=0;
            int tmp=diff[i];
            while(i<n and diff[i]==tmp)
            {
                diff[i]=tmp+(26*ct);
                i++;
                ct++;
            }
            i--;
        }
        sort(diff.begin(),diff.end());
        
        /*for(auto x: diff)
            cout<<x<<" ";
        cout<<endl;*/
        
        
        return diff[n-1]<=k;
        
        
    }
};