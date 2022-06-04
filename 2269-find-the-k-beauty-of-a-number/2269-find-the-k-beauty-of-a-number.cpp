class Solution {
public:
    int divisorSubstrings(int num, int k) 
    {
        string s = to_string(num);
        int n = s.size();
        int cnt = 0;
        for(int i=0; i<=n-k; i++)
        {
            string str = s.substr(i,k);
            int div = stoi(str);
            if(div>0 and num%div==0)
                cnt++;
        }
        return cnt;
        
    }
};