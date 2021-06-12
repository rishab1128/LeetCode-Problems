/**
 * @param {number[]} chalk
 * @param {number} k
 * @return {number}
 */
var chalkReplacer = function(chalk, k) 
{
    let sum=0;
    chalk.forEach((val)=>{
      sum+=val;          
    })
    console.log(sum);
    
    let quo=Math.floor(k/sum);
    k-=quo*sum;
    let ans=-1;
    
    for(let i=0; i<chalk.length; i++)
    {
        k-=chalk[i];
        if(k<0)
        {
            ans=i;
            break;
        }
    }
    
    
    return ans;
};