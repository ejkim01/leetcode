/*
Students are asked to stand in non-decreasing order of heights for an annual photo.
Return the minimum number of students that must move in order for all students to be standing in non-decreasing order of height.
 
Example 1:
Input: heights = [1,1,4,2,1,3]
Output: 3
 
Constraints:
1 <= heights.length <= 100
1 <= heights[i] <= 100
*/

int heightChecker(vector<int>& heights) {
    int res = 0, n = heights.size();
    vector<int> sorted = heights;
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n; ++i) {
        if (sorted[i] != heights[i]) ++res;
    }
    return res;
}