class Solution {
public:

    
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        
        if (intervals.empty()) {
            return ret;
        }
        
        std::sort(intervals.begin(), intervals.end(), lc);
        Interval cur = intervals[0];
        
        size_t len = intervals.size();
        int i = 1;
        
        while (i < len) {
            if (cur.end >= intervals[i].start) {
                cur.end = max(intervals[i].end,cur.end);
            }
            else{
                ret.push_back(cur);
                cur = intervals[i];
            }
            i++;
        }
        if (ret.empty() || ret.back().end < cur.start) {
            ret.push_back(cur);
        }
        return ret;
    }
};