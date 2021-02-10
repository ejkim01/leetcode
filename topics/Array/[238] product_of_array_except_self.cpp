/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
Example:
Input:  [1,2,3,4]
Output: [24,12,8,6]

Note: Please solve it without division and in O(n).
Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i) {
        res[i] = res[i - 1] * nums[i - 1];
    }
    int right = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
        res[i] *= right;
        right *= nums[i];
    }
    return res;
}