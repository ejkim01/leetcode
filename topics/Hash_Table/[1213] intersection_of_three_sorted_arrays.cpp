/*
Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order, return a sorted array of only the integers that appeared in all three arrays.
 
Example 1:
Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
Output: [1,5]
Explanation: Only 1 and 5 appeared in the three arrays.

 
Constraints:
1 <= arr1.length, arr2.length, arr3.length <= 1000
1 <= arr1[i], arr2[i], arr3[i] <= 2000
*/

vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    unordered_set<int> s2(arr2.begin(), arr2.end());
    unordered_set<int> s3(arr3.begin(), arr3.end());
    
    vector<int> res;
    for (int n: arr1) {
        if (s2.count(n) && s3.count(n)) res.push_back(n);
    }
    return res;
}