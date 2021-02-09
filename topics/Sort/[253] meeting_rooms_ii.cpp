/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
*/

int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.size()==0)
        return 0;
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(intervals[0][1]);

    for (int i=1; i<intervals.size(); i++) {
        int n = q.top();
        if (n<=intervals[i][0]) {
            q.pop();
        }
        q.push(intervals[i][1]);
    }
    return q.size();
}