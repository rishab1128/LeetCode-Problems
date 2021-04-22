bool comp(const  string& a1, const string& b1)
{
    string tmp1=a1+b1;
    string tmp2=b1+a1;
    return tmp1>tmp2;
}

class Solution {
public:
    string largestNumber(vector<int>& arr) 
    {
        int n=arr.size();
        vector<string>nums;
        for(int x: arr)
            nums.push_back(to_string(x));
        
        sort(nums.begin(),nums.end(),comp);
        string ans="";
        for(auto x: nums)
            ans+=x;
        if(ans[0]=='0')
            return "0";
        return ans;
    }
};