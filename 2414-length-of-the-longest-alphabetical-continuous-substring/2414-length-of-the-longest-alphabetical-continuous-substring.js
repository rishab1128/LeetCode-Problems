/**
 * @param {string} s
 * @return {number}
 */
var longestContinuousSubstring = function(s) 
{
    let n = s.length;
    var ans = 1;
    for(let i = 0 ; i < n; i++)
    {
        let j = i+1;
        let diff = 1;
        while(j<n && s[j].charCodeAt(0)-s[i].charCodeAt(0)==diff)
        {
            j++;
            diff++;
        }
        ans = Math.max(ans , j-i);
        i = j-1;
    }
    return ans;
    
};