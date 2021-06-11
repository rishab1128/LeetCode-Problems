/**
 * @param {string} firstWord
 * @param {string} secondWord
 * @param {string} targetWord
 * @return {boolean}
 */
var isSumEqual = function(firstWord, secondWord, targetWord) 
{
    let ob={
        word1:"",
        word2:"",
        word3:""
    }
    for(let x in firstWord){
        let num=firstWord[x].codePointAt(0);
        num-=97;
        ob.word1+=num;
    }
    for(let x in secondWord){
        let num=secondWord[x].codePointAt(0);
        num-=97;
        ob.word2+=num;
    }
    for(let x in targetWord){
        let num=targetWord[x].codePointAt(0);
        num-=97;
        ob.word3+=num;
    }
    
    
    let num1=Number(ob.word1);
    let num2=Number(ob.word2);
    let num3=Number(ob.word3);
    
    console.log(ob.word1 , ob.word2 , ob.word3 , num1 , num2, num3);
    return num1+num2===num3;
    
};