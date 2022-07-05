class Solution {
public:
    
    static bool cmp(const pair<int,int>&a , const pair<int,int>&b){
        return a.second<b.second;
    }
    
    vector<string> maxNumOfSubstrings(string s) 
    {
        int n = s.size();
        vector<int>firstOccu(26,-1);
        vector<int>lastOccu(26,-1);
        for(int i=0; i<n; i++)
        {
            int ele = s[i]-'a';
            if(firstOccu[ele]==-1)
                firstOccu[ele]=i;
            lastOccu[ele]=i;
        }
        
        vector<pair<int,int>>arr;
        for(int i=0; i<26; i++)
        {
            if(firstOccu[i]==-1)
                continue;
            
            int start = firstOccu[i] , end = lastOccu[i];
            for(int j=start; j<=end; j++)
            {
                start = min(start,firstOccu[s[j]-'a']);
                end = max(end,lastOccu[s[j]-'a']);
            }
            if(start==firstOccu[i])
                arr.push_back({start,end});
        }
        
        //Max no. of non-overlapping intervals in array "arr"
        sort(arr.begin(),arr.end(),cmp);
        
        vector<string>ans;
        
        int prevEnd=-1;
        for(auto [start,end] : arr)
        {
            if(start>prevEnd){
                ans.push_back(s.substr(start,end-start+1));
                prevEnd = end;
            }
        }
        
        return ans;
        
    }
};