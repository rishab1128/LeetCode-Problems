class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& cl, int ext) 
    {
        int n=cl.size();
        priority_queue<pair<double,int>>pq;
        double sum=0;
        vector<double>upt;
        for(int i=0; i<n; i++)
        {
            double frac=((double) cl[i][0])/cl[i][1];
            sum+=frac;
            double new_frac=((double) (cl[i][0]+1))/(cl[i][1]+1);
            cl[i][0]+=1;
            cl[i][1]+=1;
            double growth=new_frac-frac;
            pq.push({growth,i});
        }
        
        while(ext>0)
        {
            sum+=pq.top().first;
            ext--;
            if(ext==0)
                break;
            int idx=pq.top().second;
            pq.pop();
            double frac=((double) cl[idx][0])/cl[idx][1];
            double new_frac=((double) (cl[idx][0]+1))/(cl[idx][1]+1);
            double growth=new_frac-frac;
            pq.push({growth,idx});
            cl[idx][0]++;
            cl[idx][1]++;
        }
        //sum=ps(sum,5);
        return sum/n;
    }
};