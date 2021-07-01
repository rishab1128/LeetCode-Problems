class Solution {
public:
    long long wonderfulSubstrings(string word) 
    {
        //Represent a to j by bitmasks where 
        //a='0000000001'= 2^0 = 1                              
        //b='0000000010'= 2^1 = 2                                   
        //c='0000000100'= 2^2 = 4 
        //d='0000001000'= 2^3 = 8 
        //...and so on 

        unordered_map<char,long long>bitmask;
        int k=0;
        for(char ch='a'; ch<='j'; ch++)
        {
            bitmask[ch]=1<<k;
            k++;
        }

        //Create a prefix array of word using these bitmaks
        int n=word.size();
        vector<long long>pref(n+1);
        pref[0]=0;
        for(int i=0; i<n; i++)
        {
            char ch=word[i];
            pref[i+1]=pref[i]^bitmask[ch];
        }


        unordered_map<long long ,long long>mp;
        mp[0]++;
        long long ans=0;
        for(int i=1; i<=n; i++)
        {
            /*if(pref[i]==0)
                ans+=mp[pref[i]];*/
            
            // Add counts of substrings with all characters with even counts.
            if(mp.count(pref[i]))
                ans+=mp[pref[i]];
            
            // Add counts of substrings where only one character has odd freq
            for(int j=0; j<10; j++)
            {
                long long target=pref[i]^(1<<j);
                if(mp.count(target))
                    ans+=mp[target];
            }
            
            mp[pref[i]]++;
        }

        return ans;

    }
};