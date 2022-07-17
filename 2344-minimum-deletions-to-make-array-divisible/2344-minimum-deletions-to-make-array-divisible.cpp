class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        //Approach : 
        //gcd = GCD of all the elements of numsDivide
        //The smallest element in nums should be a factor of gcd
        
        int gcd = numsDivide[0];
        for(auto x: numsDivide)
            gcd = __gcd(gcd,x);
        
        // cout<<gcd<<endl;
        
        priority_queue<int, vector<int> , greater<>>pq;
        for(auto x: nums)
            pq.push(x);
        
        int cnt = 0;
        while(pq.size() and gcd%pq.top())
        {
            cnt++;
            pq.pop();
        }
        
        if(pq.empty())
            return -1;
        
        return cnt;
    }
};