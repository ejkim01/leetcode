/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
Example:
Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:
You can assume that you can always reach the last index.
*/

int jump(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return 0;

    int maxPos = nums[0];
    int maxSteps = nums[0];

    int jumps = 1;
    for (int i = 1; i < n; ++i) {
        // if to reach this point 
        // one needs one more jump
        if (maxSteps < i) {
            ++jumps;
            maxSteps = maxPos;
        }
        maxPos = max(maxPos, nums[i] + i);
    }
    return jumps;
}