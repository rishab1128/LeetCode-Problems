/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> sched) 
    {
        vector<Interval>res;
        for(auto arr : sched)
        {
            for(auto inter : arr)
                res.push_back(inter);
        }
        
        sort(res.begin(),res.end(),[](auto &ele1, auto &ele2) {
            return ele1.start == ele2.start ? ele1.end < ele2.end : ele1.start < ele2.start;
        });
        
        int end=-1;
        vector<Interval>ans;
        for(auto ele : res)
        {
            if(ele.start>end)
            {
                if(end!=-1)
                    ans.emplace_back(end,ele.start);
                end = ele.end;
            }
            else
                end = max(end,ele.end);
        }
        return ans;
        
        
    }
};