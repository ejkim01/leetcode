/*
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
Example:
Input: nums = [3,5,2,1,6,4]
Output: One possible answer is [3,5,1,6,2,4]
*/

void wiggleSort(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    if (nums.size() <= 2) return;
    for (int i = 2; i < nums.size(); i += 2) {
        swap(nums[i], nums[i - 1]);
    }
}
