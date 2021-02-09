/*
Given a collection of intervals, merge all overlapping intervals.
Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/

vector<Interval> merge(vector<Interval>& intervals) {
    std::sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {return a.start < b.start;});
    
    if (intervals.empty()) return {};
    vector<Interval> res = {intervals[0]};
    for (int i = 1; i < intervals.size(); ++i) {
        if (res.back().end < intervals[i].start) {
            res.push_back(intervals[i]);
        } else {
            res.back().end = max(res.back().end, intervals[i].end);
        }
    }   
    return res;
}