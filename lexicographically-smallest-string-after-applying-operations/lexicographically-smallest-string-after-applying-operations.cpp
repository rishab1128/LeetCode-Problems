class Solution {
public:
    string add(string s , int&a)
    {
        int n=s.size();
        for(int i=1; i<n; i+=2)
        {
            int x=((s[i]-'0')+a)%10;
            s[i]='0'+x;
        }
        return s;
    }
    
    string rot(string s , int&b)
    {
        int n=s.size();
        string back=s.substr(n-b);
        string front=s.substr(0,n-b);
        return back+front;
    }
    
    string findLexSmallestString(string s, int a, int b) 
    {
        unordered_map<string,int>vis;
        vis[s]=1;
        string ans=s;
        queue<string>q;
        q.push(s);
        while(q.size()>0)
        {
            string t=q.front() ;
            q.pop();
            ans=min(ans,t);
            string addT=add(t , a);
            string rotT=rot(t , b);
            if(vis.find(addT)==vis.end())
            {
                q.push(addT);
                vis[addT]=1;
            }
            if(vis.find(rotT)==vis.end())
            {
                q.push(rotT);
                vis[rotT]=1;
            }
            
        }
        
        return ans;
        
    }
};