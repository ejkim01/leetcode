/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9such that each row, column, and both diagonals all have the same sum.
Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).
 
Example 1:
Input: [[4,3,8,4],
        [9,5,1,9],
        [2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:
438
951
276

while this one is not:
384
519
762

In total, there is only one magic square inside the given grid.

Note:
1 <= grid.length <= 10
1 <= grid[0].length <= 10
0 <= grid[i][j] <= 15
*/

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m - 2; ++i)
            for (int j = 0; j < n - 2; ++j)
                ans += magic(grid, j, i);
        return ans;
    }
private:
    int magic(const vector<vector<int>>& grid, int x, int y) {
        vector<int> rows(3);
        vector<int> cols(3);
        vector<int> exps{15, 15, 15};
        int dig = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int v = grid[y + i][x + j];
                if (v <= 0 || v > 9) return 0; // must between 1 and 9
                rows[i] += v;
                cols[j] += v;
                if (i == j) dig += v;
            }
        }
        return rows == exps && cols == exps && dig == 15;
    }
};
