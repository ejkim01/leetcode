/*
We define a harmounious array as an array where the difference between its maximum value and its minimum value is exactly 1.
Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.
Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
*/

int findLHS(vector<int>& nums) {
    unordered_map<int, int> m;
    int res = 0;
    
    for (int n: nums) {
        m[n]++;
    }
    for (int i=0; i<nums.size(); i++) {
        if (m.count(nums[i]+1)) {
                res = max(res, m[nums[i]] + m[nums[i]+1]);
        }
    }
    return res;
}
