/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
You need to find the shortest such subarray and output its length.
Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/

int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size(), i = 0, j = n - 1;
    vector<int> t = nums;
    sort(t.begin(), t.end());
    while (i < n && nums[i] == t[i]) ++i;
    while (j > i && nums[j] == t[j]) --j;
    return j - i + 1;
}
