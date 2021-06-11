/**
 * @param {number[]} nums
 * @return {number}
 */
var reductionOperations = function(nums) 
{
    nums=nums.sort(function(x,y){
        return y-x;
    })
    
    let n=nums.length;
    let pref=[...Array(n)];
    pref[0]=0;
    for(let i=1; i<n; i++)
    {
        if(nums[i]==nums[i-1])
            pref[i]=pref[i-1];
        else
            pref[i]=pref[i-1]+i;
    }
    
    
    console.log(pref);
    console.log(n);
    
    
    return pref[n-1];
    
};