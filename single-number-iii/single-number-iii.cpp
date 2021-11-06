class Solution {
public:
    vector<int> singleNumber(vector<int>& arr) 
    {
        int Xor=0;
        for(auto x: arr)
            Xor^=x;
        
        //Find any arbitrary set bit of Xor - let's find the lowest set bit(i) of Xor
        int i=0;
        for(int bit=0; bit<32; bit++)
        {
            if(Xor&(1<<bit))
            {
                i=bit;
                break;
            }
        }
        
        //Let's say x^y=Xor
        //To find one of the numbers say x , we xor all the elements which has ith bit set
        int x=0;
        for(auto ele : arr)
        {
            if(ele&(1<<i))
                x^=ele;
        }
        
        int y=Xor^x;
        
        return {x,y};
        
    }
};