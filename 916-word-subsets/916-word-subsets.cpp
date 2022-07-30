class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        vector<int>overallFreq(26,0);
        for(auto word : words2)
        {
            vector<int>tmpFreq(26,0);
            for(auto ch : word)
                tmpFreq[ch-'a']++;
            
            for(int i=0; i<26; i++)
                overallFreq[i] = max(overallFreq[i],tmpFreq[i]);
        }
        
        
        vector<string>ans;
        for(auto word : words1)
        {
            vector<int>tmpFreq(26,0);
            bool flag = 1;
            
            for(auto ch : word)
                tmpFreq[ch-'a']++;
            
            
            for(int i=0; i<26; i++)
            {
                if(tmpFreq[i]<overallFreq[i])
                {
                    flag = 0;
                    break;
                }
            }
            
            if(flag)
                ans.push_back(word);
        }
        
        return ans;
        
    }
};