/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    struct cmp{
        bool operator()(Interval a, Interval b){
            if(a.start <= b.start){
                if(a.start == b.start){
                    return a.end < b.end;
                }
                return true;
            }
            else
                return false;
        }
    };
    vector<Interval> merge(vector<Interval>& intervals) {   //we could merge while right edge of b not less than right edge of a 
        sort(intervals.begin(), intervals.end(), cmp());
        vector<Interval> res;
        if(intervals.size() == 0)
            return res;
        res.push_back(intervals[0]);
            for(int i = 1; i < intervals.size();i++){
                if(res.back().start != intervals[i].start){
                    if(res.back().end < intervals[i].start){        //cannot be merged
                        res.push_back(intervals[i]);
                    }   
                    else{                                               //could be merged
                        res.back().end = max(res.back().end,intervals[i].end);
                    }
                }
                else{
                    res.back().end = intervals[i].end;
                }
            }
        return res;
    }
};