bool cmp(const vector<int>&a , const vector<int>&b)
{
    return a[1]<b[1];
}

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses)
    {
        int n=courses.size();
        sort(courses.begin() , courses.end() , cmp);  //Greedy Approach : Finish the courses with earliest deadlines first
        priority_queue<int>pq;                        //PQ holds the duration of all the courses taken so far
        int currTotalTime=0 , ans=0;
        for(int i=0; i<n; i++)
        {
            int dur=courses[i][0] , currDeadLine=courses[i][1];
            if(currTotalTime+dur<=currDeadLine)
            {
                currTotalTime+=dur;
                pq.push(dur);
                ans++;
            }
            else
            {
                if(pq.size()>0){
                    int MaxDur=pq.top();
                    if(MaxDur>dur)
                    {
                        pq.pop();
                        currTotalTime=currTotalTime-MaxDur+dur;
                        pq.push(dur);
                    }
                }
               
            }
        }
        return ans;
        
    }
};