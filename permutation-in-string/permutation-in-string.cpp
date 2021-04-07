class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int k=s1.size() , n=s2.size();
        if(k>n)
            return false;
        map<char,int>mp1,mp2;
        for(int i=0; i<k; i++)
        {
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        if(mp1==mp2)
            return true;
        int j=0 , flag=0;
        for(int i=k; i<n; i++)
        {
            mp2[s2[i]]++;
            if(mp2[s2[j]]>0)
            {
                mp2[s2[j]]--;
                if(mp2[s2[j]]==0)
                    mp2.erase(s2[j]);
                j++;
            }
            if(mp2==mp1)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            return true;
        return false;
        
        
    }
};