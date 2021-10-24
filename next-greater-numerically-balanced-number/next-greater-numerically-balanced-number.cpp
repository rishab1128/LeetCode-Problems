class Solution {
public:
    vector<int>arr;
    
    void generate(int num)
    {
        if(num==7)
        {
            arr.push_back(1224444);
            return;
        }
        
        for(int i=0; i<(num+1)/2; i++)
        {
            int x=i,y=num-i;
            char X=i+'0' , Y=y+'0';
            string s1(x,X);
            string s2(y,Y);
            string s=s1+s2;
            do 
            {
                //cout<<s<<endl;
                int x=stoi(s);
                arr.push_back(x);
            }while (next_permutation(s.begin(),s.end()));
        }
        
        if(num==6)
        {
            string s="122333";
            do 
            {
                int x=stoi(s);
                arr.push_back(x);
            }while (next_permutation(s.begin(),s.end()));
        }
    }
    
    int nextBeautifulNumber(int n)
    {
        arr.clear();
        arr={1,22};
        for(int digit=3; digit<=7; digit++)
            generate(digit);
        sort(arr.begin(),arr.end());
        int ans=*upper_bound(arr.begin(),arr.end(),n);
        return ans;
    }
};