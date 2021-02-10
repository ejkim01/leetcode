/*
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
 
Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]

Explanation:
*/

vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return {};
    int m = matrix.size(), n = matrix[0].size(), r = 0, c = 0;
    vector<int> res(m * n);
    for (int i = 0; i < m * n; ++i) {
        res[i] = matrix[r][c];
        if ((r + c) % 2 == 0) {
            if (c == n - 1) {++r;}        ⇒ this line should precede
            else if (r == 0) {++c;}      
            else {--r; ++c;}
        } else {
            if (r == m - 1) {++c;}       ⇒ this line should precede
            else if (c == 0) {++r;}
            else {++r; --c;}
        }
    }
    return res;
}