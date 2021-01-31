/*
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.
Return the intersection of these two interval lists.
(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers xwith a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)
 
Example 1:

Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.
*/

vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
    vector<Interval> res;
    int pa=0, pb=0;
    while(pa<A.size() && pb<B.size()) {
        if(A[pa].end<B[pb].start) pa++;
        else if(A[pa].start>B[pb].end) pb++;
        else {
            res.push_back({max(A[pa].start, B[pb].start), min(A[pa].end, B[pb].end)});
            if(A[pa].end<B[pb].end) pa++;
            else pb++;
        }
    }
    return res;  
}
