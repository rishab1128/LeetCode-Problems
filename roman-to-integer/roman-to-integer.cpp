class Solution {
public:
    int romanToInt(string s) 
    {
        vector<char>arr={'I','V','X','L','C','D','M'};
        vector<int>brr={1,5,10,50,100,500,1000};
        map<char,int>mp;
        for(int  i=0 ; i<arr.size() ; i++)
            mp[arr[i]]=brr[i];
        
        vector<string>b={"IV","IX","XL","XC","CD","CM"};
        vector<int>t={4,9,40,90,400,900};
        map<string,int>mp2;
        for(int i=0; i<b.size() ; i++)
            mp2[b[i]]=t[i];
        
        int ans=0;
        int n=s.size() ;
        for(int i=0; i<n; i++)
        {
            if(i!=n-1 and (s[i]=='I' || s[i]=='X' || s[i]=='C') and mp[s[i+1]]>mp[s[i]])
            {
                string t="";
                t+=s[i];
                t+=s[i+1];
                //cout<<t<<endl;
                ans+=mp2[t];
                i++;
            }
            else
                ans+=mp[s[i]];
                
        }
        return ans;
    }
};