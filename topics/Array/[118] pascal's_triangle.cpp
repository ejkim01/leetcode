/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.
Example:
Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for (int i=0; i<numRows; ++i) {
        res.push_back(vector<int>(i+1, 1));
        for (int j=1; j<i; ++j)
            res[i][j] = res[i-1][j-1] + res[i-1][j];
    }
    return res;
}
