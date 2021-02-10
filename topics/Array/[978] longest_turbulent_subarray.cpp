/*
A subarray A[i], A[i+1], ..., A[j] of A is said to be turbulent if and only if:
For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when k is even;
OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] when k is odd.
That is, the subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.
Return the length of a maximum size turbulent subarray of A.
 
Example 1:
Input: [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: (A[1] > A[2] < A[3] > A[4] < A[5])
 
Example 2:
Input: [4,8,12,16]
Output: 2
 
Example 3:
Input: [100]
Output: 1
 
 
Note:
1 <= A.length <= 40000
0 <= A[i] <= 10^9
*/

int maxTurbulenceSize(vector<int>& A) {
    vector<int> up(A.size(), 1);
    vector<int> down(A.size(), 1);
    int ans = 1;
    for (int i = 1; i < A.size(); ++i) {
        if (A[i] > A[i - 1]) up[i] = down[i - 1] + 1;
        if (A[i] < A[i - 1]) down[i] = up[i - 1] + 1;
        ans = max(ans, max(up[i], down[i]));      
    }
    return ans;        
}