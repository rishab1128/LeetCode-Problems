class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) 
    {
        int n=words.size() , ans=0;
        
        map<char,int>freq;
        for(auto ch:letters)
            freq[ch]++;
        
        for(int num=1; num<(1<<n); num++)
        {
            vector<int>tmp;
            for(int j=0; j<n; j++)
            {
                if(num&(1<<j))
                    tmp.push_back(j);
            }
            
            map<char,int>mp;
            string s="";
            int total=0;
            
            for(auto i: tmp)
                s+=words[i];
            
            for(auto x: s){
                mp[x]++;
                total+=score[x-'a'];
            }
            
            bool flag=1;
            for(auto z: mp)
            {
                char ch=z.first;
                if(freq.find(ch)!=freq.end() and mp[ch]<=freq[ch])
                    continue;
                else
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
                ans=max(ans,total);
        }
        
        return ans;
        
    }
};