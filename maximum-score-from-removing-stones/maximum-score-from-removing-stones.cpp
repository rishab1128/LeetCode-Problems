class Solution {
public:
    int maximumScore(int a, int b, int c) 
    {
        priority_queue<int>pq;
        int ct=0,ans=0;
        pq.push(a),pq.push(b),pq.push(c);
        while(ct<2)
        {
            if(ct>=2)
                break;
            int x1=pq.top();
            pq.pop();
            int x2=pq.top();
            pq.pop();
            x1--;
            x2--;
            ans++;
            if(x1==0&&x2==0)
                ct+=2;
            else if((x1==0&&x2!=0)||(x1!=0&&x2==0))
                ct+=1;
            if(x1>0)
                pq.push(x1);
            if(x2>0)
                pq.push(x2);
        }
        return ans;
    }
};