/*
Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].
Return any permutation of A that maximizes its advantage with respect to B.
 
Example 1:
Input: A = [2,7,11,15], B = [1,10,4,11]
Output: [2,11,7,15]
 
Example 2:
Input: A = [12,24,8,32], B = [13,25,32,11]
Output: [24,32,8,12]
 
 
Note:
1 <= A.length = B.length <= 10000
0 <= A[i] <= 10^9
0 <= B[i] <= 10^9
*/

vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    vector<pair<int, int>> arr;
    for (int i=0; i<B.size(); i++) {
        arr.push_back(make_pair(B[i], i));
    }
    sort(A.begin(), A.end());
    sort(arr.begin(), arr.end());
    int j = 0;
    int k = B.size()-1;
    for (int i=0; i<A.size(); i++) {
        // 12, 24, 8, 32
        // 13, 25, 32, 11
        // If the value in A is smaller than B, move it to the position of greatest value of B
        if (arr[j].first<A[i]) {
            B[arr[j].second] = A[i];
            j++;
        } else {
            B[arr[k].second] = A[i];
            k--;
        }
    }
    return B;
}