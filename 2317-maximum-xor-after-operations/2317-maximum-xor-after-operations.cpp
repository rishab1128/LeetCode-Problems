class Solution {
public:
    int maximumXOR(vector<int>& arr) 
    {   
        long long res = 0 , bits = 0;
        for(auto x: arr){
            res^=x;
            if(x>0)
                bits = max(bits , (long long)log2(x));
        }
        
        // cout<<bits<<endl;
        
        for(int i=bits; i>=0; i--)
        {
            long long num = (1<<i);
            if(num&res)
                continue;
            else
            {
                int one = 0 , zero = 0;
                for(auto x: arr)
                {
                    if(x&num)
                        one++;
                    else
                        zero++;
                }
                if(one>0 and one%2==0)
                    res+=num;
            }
        }
        
        return res;
        
            
        
        
        
    }
};