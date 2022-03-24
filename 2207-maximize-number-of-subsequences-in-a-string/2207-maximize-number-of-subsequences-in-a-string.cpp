class Solution {
public:
    long long maximumSubsequenceCount(string text, string patt) 
    {
        int n=text.size();
        long long ans0 = 0 , ans1 = 0;
        
        if(patt[0]==patt[1])
        {
            long long ans=0 , ct=0;
            for(auto x: text)
            {
                if(x==patt[0])
                    ct++;
            }
            ct++;
            ans=ct*(ct-1)/2;
            return ans;
        }
        
        vector<int>pos0 , pos1;
        pos0.push_back(0);
        for(int i=0; i<n; i++)
        {
            if(text[i]==patt[0])
                pos0.push_back(i+1);
            else if(text[i]==patt[1])
                pos1.push_back(i+1);
        }
        
        int n0=pos0.size() , n1=pos1.size();
        for(int i=0; i<(int)pos0.size(); i++)
        {
            int posi = upper_bound(pos1.begin(),pos1.end(),pos0[i])-pos1.begin();
            ans0+=n1-posi;
        }
        
        pos0.clear();
        pos1.clear();
        for(int i=0; i<n; i++)
        {
            if(text[i]==patt[0])
                pos0.push_back(i);
            else if(text[i]==patt[1])
                pos1.push_back(i);
        }
        pos1.push_back(n);
        
        
        n0=pos0.size() , n1=pos1.size();
        for(int i=0; i<(int)pos1.size(); i++)
        {
            int posi = upper_bound(pos0.begin(),pos0.end(),pos1[i])-pos0.begin();
            ans1+=posi;
        }
        
        
        return max(ans0 ,  ans1);
    }
};