class Solution {
public:
    string pushDominoes(string d) 
    {
        d = 'L' + d + 'R';
        string res = "";
        
        for (int i = 0, j = 1; j < d.length(); ++j) 
        {
            if (d[j] == '.') 
                continue;
            int middleLen = j - i - 1;
            if (i > 0)
                res += d[i];
            if (d[i] == d[j])
                res += string(middleLen, d[i]);
            else if (d[i] == 'L' && d[j] == 'R')
                res += string(middleLen, '.');
            else
                res += string(middleLen / 2, 'R') + string(middleLen % 2, '.') + string(middleLen / 2, 'L');
            i = j;
        }
        return res;
    }
};