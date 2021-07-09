class Solution {
public:
    //Refer solution for more details
    //See Note
    int reverse(int x) 
    {
        int rev=0;
        while(x!=0)
        {
            //Pop op. using math
            int pop=x%10;
            x/=10;
            
            //Check for overflow
            if(rev>INT_MAX/10 || (rev==INT_MAX/10 && pop>7))return 0;
            if(rev<INT_MIN/10 || (rev==INT_MIN/10 && pop<-8))return 0;
            
            //Push op. using math
            rev=rev*10+pop;
            
        }
        return rev;
        
    }
};