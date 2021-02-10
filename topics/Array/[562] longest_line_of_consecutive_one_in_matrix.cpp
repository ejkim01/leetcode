/*
Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.
Example:
Input:
[[0,1,1,0],
 [0,1,1,0],
 [0,0,0,1]]
Output: 3

Hint: The number of elements in the given matrix will not exceed 10,000.
*/

int longestLine(vector<vector<int>>& M) {
    if (M.size()==0) return 0;
    int res = 0;
    int row = M.size();
    int col = M[0].size();
    vector<vector<vector<int>>> dp(row+1, vector<vector<int>>(col+2, vector<int>(4, 0)));
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (M[i][j]==1) {
                dp[i+1][j+1][0] = dp[i+1][j][0] + 1;
                res = max(res, dp[i+1][j+1][0]);

                dp[i+1][j+1][1] = dp[i][j+1][1] + 1;
                res = max(res, dp[i+1][j+1][1]);

                dp[i+1][j+1][2] = dp[i][j][2] + 1;
                res = max(res, dp[i+1][j+1][2]);

                dp[i+1][j+1][3] = dp[i][j+2][3] + 1;
                res = max(res, dp[i+1][j+1][3]);
            }
        }
    }
    return res;
}