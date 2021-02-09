/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.
Example 1:
Input: [1,2,3,4,5]
Output: true

Example 2:
Input: [5,4,3,2,1]
Output: false
*/

bool increasingTriplet(vector<int>& nums) {
    int m1 = INT_MAX, m2 = INT_MAX;
    for (auto a : nums) {
        if (m1 >= a) m1 = a;
        else if (m2 >= a) m2 = a;
        else return true;
    }
    return false;
}