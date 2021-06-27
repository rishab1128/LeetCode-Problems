class Solution {
public:
    
    //Using Z-Algorithm for pattern matching
    
    //Construct z-array in optimal way -> TC: O(n) where n=s.size()
    void optimally_construct_z_array(string s, vector<int>&z)
    {
        int l=0;
        int r=0;

        int n=s.size();
        for(int i=1; i<n; i++)
        {
            if(i>r)
            {
                // i does not lie b/w l and r
                // z for this i does not exist
                l=i;
                r=i;
                while(r<n && s[r-l]==s[r]){
                    r++;
                }
                z[i]=r-l;
                r--;
            }
            else
            {
                int k=i-l;
                if(i+z[k]<=r)
                {
                    //i lies b/w l and r
                    // z will exist previously
                    z[i]=z[k];
                }
                else
                {
                    //Some part of z is already included
                    //You have to start matching further
                    l=i;
                    while(r<n && s[r-l]==s[r]){
                        r++;
                    }
                    z[i]=r-l;
                    r--;
                }
            }
        }
    }
    
    void solve(string&text, string pattern , string&ans)
    {
        while(1)
        {
            int flag=0;
            string s=pattern+'$'+text;
            //cout<<s<<" "<<text<<endl;
            int n=s.size();
            int m=pattern.size();
            vector<int>z(n,0);
            optimally_construct_z_array(s,z);
            for(auto x: z)
            {
                if(x!=m)
                    continue;
                else
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                ans=text;
                break;
            }
            else
            {
                int tmp=1;
                for(int i=0; i<n; i++)
                {
                    if(i>m && z[i]==m)
                    {
                        int idx=i-m-1;
                        if(idx+m<=text.size())
                        {
                            text.erase(idx,m);
                            tmp=0;
                            break;   
                        }
                    }
                }
                
            }
        }
        
    }
    
    string removeOccurrences(string text, string pattern) 
    {
        string ans="";
        solve(text,pattern,ans);
        return ans;
    }
};