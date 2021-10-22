//Refer : https://www.youtube.com/watch?v=0Oef3MHYEC0
class Solution {
public:
    //Using Maths
    bool canMeasureWater(int jug1, int jug2, int target) 
    {
        if(jug1+jug2<target)
            return false;
        
        if(jug1==target || jug2==target || jug1+jug2==target)
            return true;
        
        int gcd=__gcd(jug1,jug2);
        
        if(target%gcd==0)
            return true;
        
        return false;
        
    }
};