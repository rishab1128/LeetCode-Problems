using STR=string;
using vs=vector<string>;
#define pb  push_back

class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    void func(STR input, STR output, vs& v)
    {
        if(input.size()==0)
        {
            v.pb(output);
            return;
        }
        STR rest=input.substr(1);
        if(input[0]>='a'&& input[0]<='z')
        {
            func(rest,output+input[0],v);
            func(rest,output+(char)toupper(input[0]),v);
        }
        else if(input[0]>='A'&& input[0]<='Z')
        {
            func(rest,output+input[0],v);
            func(rest,output+(char)tolower(input[0]),v);
        }
        else
        {
            func(rest,output+input[0],v);
        }
    }
    
    vector<string> letterCasePermutation(string s) 
    {
        vs ans;
        func(s,"",ans);
        return ans;
    }
};