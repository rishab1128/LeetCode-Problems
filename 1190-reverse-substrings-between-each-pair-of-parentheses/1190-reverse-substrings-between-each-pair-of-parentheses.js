/**
 * @param {string} s
 * @return {string}
 */
var reverseParentheses = function(s) 
{
    let ans="",tmp="";
    let stack = [];
    for(let idx in s)
    {
        let x = s[idx];
        if(x!=')')
        {
            if(x=='(' || stack.length)
                stack.push(x);                
            else
                ans+=x;
        }
        else
        {
            tmp="";
            while(stack.length && stack[stack.length-1]!='(')
            {
                tmp+=stack.pop();
            }
            stack.pop();
            if(stack.length)
            {
                for(let y in tmp)
                    stack.push(tmp[y]);
            }
            else
                ans+=tmp;
        }
    }
    
    return ans;
};