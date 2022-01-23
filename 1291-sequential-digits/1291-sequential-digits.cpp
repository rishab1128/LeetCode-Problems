class Solution {
public:
    vector<int>generate(int digits)
    {
        vector<int>arr;
        for(int i=1; i<=10-digits; i++)
        {
            int num=i,k=i;
            for(int j=1; j<digits; j++)
            {
                k++;
                num=num*10+k;
            }
            arr.push_back(num);
        }
        return arr;
    }
    
    vector<int> sequentialDigits(int low, int high) 
    {
        vector<int>arr;
        for(int digits=2; digits<=9; digits++)
        {
            vector<int>tmp=generate(digits);
            for(auto x: tmp)
                arr.push_back(x);
        }
        
        int pos1=lower_bound(arr.begin(),arr.end(),low)-arr.begin();
        int pos2=upper_bound(arr.begin(),arr.end(),high)-arr.begin();
        pos2--;
        
        vector<int>ans;
        for(int i=pos1; i<=pos2; i++)
            ans.push_back(arr[i]);
        
        
        return ans;
        
        
    }
};