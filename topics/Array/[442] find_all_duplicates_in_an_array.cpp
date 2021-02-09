/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements that appear twice in this array.
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] < 0) res.push_back(idx + 1);
        nums[idx] = -nums[idx];
    }
    return res;
}