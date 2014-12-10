class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int len = intervals.size();
        
        int flag = 0;
        vector<Interval> ret;
        if(len <= 0){
            ret.push_back(newInterval);
            return ret;
        }
            
        int i = 0;
        for(;i < len;){
            if(intervals[i].start < newInterval.start && intervals[i].end > newInterval.end){
                ret.push_back(intervals[i++]);
                flag = 1;
                break;
            }else if(intervals[i].end < newInterval.start){
                ret.push_back(intervals[i++]);
                
            }else if(intervals[i].start > newInterval.end){
                ret.push_back(newInterval);
                flag = 1;
                break;
            }
            else {
                newInterval.start = min(newInterval.start,intervals[i].start);
                newInterval.end = max(newInterval.end,intervals[i].end);
                ++i;
                if(i == len && flag == 0){
                    ret.push_back(newInterval);
                    flag = 1;
                }
            }
        }
        
        if(flag == 0)
            ret.push_back(newInterval);
        
        while(i < len){
            ret.push_back(intervals[i]);
            ++i;
        }
        return ret;
    }
};