class Solution {
public:
    int countAsterisks(string s) 
    {
        int n = s.size();
        int i = 0;
        string t="";
        vector<string>ans;
        while(i<n)
        {
            if(s[i]=='|')
            {
                ans.push_back(t);
                t="";
            }
            else
            {
                t+=s[i];
            }
            i++;
        }
        ans.push_back(t);
        
        int m = ans.size();
        int cnt = 0;
        for(int i=0; i<m; i++)
        {
            string str = ans[i];
            if(i%2==0)
            {
                for(auto ch: str)
                {
                    if(ch=='*')
                        cnt++;
                }
            }
        }
        
        // for(int i=0; i<ans.size(); i++)
        // {
        //     cout<<i<<" ";
        //     string x=ans[i];
        //     if(!x.size())
        //         x="?";
        //     cout<<x<<endl;
        // }
            
        
        return cnt;
        
    }
    

};