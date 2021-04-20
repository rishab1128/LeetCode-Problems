#define d2b(n,x)     bitset<x>(n).to_string() //x-no.of bits and n=number
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int biit) 
    {
        int n=nums.size();
        int prefXor[n];
        prefXor[0]=nums[0];
        for(int i=1; i<n; i++)
        {
            prefXor[i]=prefXor[i-1]^nums[i];
        }
        vector<int>ans(n);
        for(int i=n-1; i>=0; i--)
        {
            int N=prefXor[i];
            int k=(1<<biit)-1;
            string bin=d2b(N,32);
            //cout<<bin<<endl;
            reverse(bin.begin(),bin.end());
            //cout<<bin<<endl;
            for(int j=0; j<biit; j++)
                k-=bin[j]=='1'?(1<<j):0;
            ans[i]=k;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};