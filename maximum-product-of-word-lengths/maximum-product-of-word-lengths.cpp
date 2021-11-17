class Solution {
public:
    int maxProduct(vector<string>& words) 
    {
        int n=words.size();
        vector<int>arr(n,0);
        for(int i=0; i<n; i++)
        {
            vector<int>mp(26,0);
            for(auto ch : words[i])
            {
                int x=ch-'a';
                if(mp[x]==0){
                    arr[i]+=(1<<x);
                    mp[x]=1;
                }
            }
        }
        
        int ans=0;
        for(int i=0; i<n; i++)
        {
            int num1=arr[i];
            int len1=words[i].size();
            for(int j=i+1; j<n; j++)
            {
                int num2=arr[j];
                bool flag=1;
                for(int k=0; k<26; k++)
                {
                    if(num1&(1<<k) and num2&(1<<k)){
                        flag=0;
                        break;
                    }
                }
                if(flag){
                    int len2=words[j].size();
                    ans=max(ans , len1*len2);
                }
            }
        }
        
        return ans;
        
        
    }
};