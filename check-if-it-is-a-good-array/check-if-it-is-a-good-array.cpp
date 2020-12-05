#include<bits/stdc++.h>
using namespace std;
​
class Solution {
public:
    //Application of Linear Diophantine Equation
    //Approach : Check if there is a pair of co-prime numbers in the array OR Just check the gcd of whole array if it is 1 ans =true else false
    bool isGoodArray(vector<int>& nums) 
    {
        int gcd=nums[0];
        int n=nums.size();
        for(int i=1; i<n; i++)
        {
            gcd=__gcd(gcd,nums[i]);
        }
        if(gcd==1)
            return true;
        return false;
    }
};
