class Solution {
public:
    //Refer  : https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/discuss/1502211/Monostack-sort-of
    
    string smallestSubsequence(string s, int k, char letter, int rep) 
    {
        int extraLetter=count(s.begin() , s.end() , letter)-rep;
        int maxRemove=s.size()-k;
        string mono,ans;
        for(auto ch: s)
        {
            while(mono.size()>0 and maxRemove and mono.back()>ch)
            {
                if(mono.back()==letter and extraLetter==0)
                    break;
                if(mono.back()==letter)
                    extraLetter--;
                maxRemove--;
                mono.pop_back();
            }
            mono.push_back(ch);
        }
        //cout<<mono<<endl;
        for(int i=0; ans.size()<k; i++)
        {
            if(mono[i]!=letter and ans.size()+max(0,rep)>=k)
                continue;
            ans.push_back(mono[i]);
            if(mono[i]==letter)
                rep--;
        }
        return ans;
    }
};