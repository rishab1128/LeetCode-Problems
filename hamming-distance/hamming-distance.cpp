class Solution {
public:
    int hammingDistance(int x, int y) 
    {
        int ans=0;
        for(int i=0; i<32; i++)
        {
            int x1=x&(1<<i);
            int y1=y&(1<<i);
            //cout<<x1<<" "<<y1<<endl;
            if( (x1>0 and y1>0) or (x1==0 and y1==0) )
                continue;
            else{
                //cout<<i<<endl;
                ans++;
            }
                
        }
        return ans;
        
    }
};