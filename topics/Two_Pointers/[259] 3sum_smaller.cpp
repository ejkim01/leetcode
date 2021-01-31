/*
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
Example:
Input: nums = [-2,0,1,3], and target = 2
Output: 2 
Explanation: Because there are two triplets which sums are less than 2:
             [-2,0,1]
             [-2,0,3]

Follow up: Could you solve it in O(n2) runtime?
*/

// O(n^2)
int threeSumSmaller(vector<int>& nums, int target) {
    if (nums.size() < 3) return 0;
    int res = 0, n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1, right = n - 1;
        while (left < right) {
            if (nums[i] + nums[left] + nums[right] < target) {
                res += right - left;
                ++left;
            } else {
                --right;
            }
        }
    }
    return res;
}

//O(n^3)
int threeSumSmaller(vector<int>& nums, int target) {
    int res = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < int(nums.size() - 2); ++i) {
        int left = i + 1, right = nums.size() - 1, sum = target - nums[i];
        for (int j = left; j <= right; ++j) {
            for (int k = j + 1; k <= right; ++k) {
                if (nums[j] + nums[k] < sum) ++res;
            }
        }
    }
    return res;
}
