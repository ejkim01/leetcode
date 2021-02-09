/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
Example 1:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.size()==0 || matrix[0].size()==0) 
        return {};
    vector<int> res;
    int left = 0;
    int right = matrix[0].size() - 1;
    int top = 0;
    int bottom = matrix.size() - 1;
    int row = 0;
    int col = 0;
    
    while (left<right && top<bottom) {
        for (int i=left; i<right; i++) res.push_back(matrix[top][i]);
        for (int i=top; i<bottom; i++) res.push_back(matrix[i][right]);
        for (int i=right; i>left; i--) res.push_back(matrix[bottom][i]);
        for (int i=bottom; i>top; i--) res.push_back(matrix[i][left]);
        left++;
        right--;
        top++;
        bottom--;
    }
    
    if (left==right) {
        for (int i=top; i<=bottom; i++)
            res.push_back(matrix[i][left]);
    } else if (top==bottom) {
        for (int i=left; i<=right; i++)
            res.push_back(matrix[top][i]);
    }
    return res;
}
