/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
Note:
The solution set must not contain duplicate quadruplets.
Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

vector<vector<int>> fourSum(vector<int> &nums, int target) {
    set<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < int(nums.size() - 3); ++i) {
        for (int j = i + 1; j < int(nums.size() - 2); ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int left = j + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    vector<int> out{nums[i], nums[j], nums[left], nums[right]};
                    res.insert(out);
                    ++left; --right;
                } else if (sum < target) ++left;
                else --right;
            }
        }
    }
    return vector<vector<int>>(res.begin(), res.end());
}
