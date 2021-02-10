/*
Given an array A of integers, return true if and only if we can partition the array into three non-empty parts with equal sums.
Formally, we can partition the array if we can find indexes i+1 < j with (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1])
 
Example 1:
Input: A = [0,2,1,-6,6,-7,9,1,2,0,1]
Output: true
Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1

Example 2:
Input: A = [0,2,1,-6,6,7,9,-1,2,0,1]
Output: false

Example 3:
Input: A = [3,3,6,5,-2,2,5,1,-9,4]
Output: true
Explanation: 3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
 
Constraints:
3 <= A.length <= 50000
-10^4 <= A[i] <= 10^4
*/

bool canThreePartsEqualSum(vector<int>& A) {
    int sum = 0;
    for (int i = 0; i < A.size(); i++) {
        sum += A[i];
    }
    if (sum % 3 != 0) {
        return false;
    }
    sum = sum / 3;
    int suma = A[0], sumc = A[A.size() - 1];
    int i = 1, j = A.size() - 2;
    while (i < j) {
        if (suma != sum) {
            suma += A[i++];
        }
        if (sumc != sum) {
            sumc += A[j--];
        }
        if (suma == sum && sumc == sum && i <= j) {
            return true;
        }
    }
    return false;        
}