/**
 * @param {number[]} bits
 * @return {boolean}
 */
var isOneBitCharacter = function(bits) 
{
    const sz=bits.length;
    for(let i=0; i<sz; i++)
    {
        if(bits[i]==1)
        {
            i++;
            if(i==sz-1)
                return false;
        }
    }
    return true;
};