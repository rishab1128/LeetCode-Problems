class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        int x=n&(n-1);
        // cout<<x<<endl;
        return x==0;
    }
};