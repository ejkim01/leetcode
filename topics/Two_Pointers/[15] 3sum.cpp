/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
The solution set must not contain duplicate triplets.
Example:
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/


vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if(nums.size()<=2)return result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
        int a = nums[i];
        //if (a > 0) break;
        if (i > 0 && a == nums[i - 1]) continue;		//skip when duplicated
        for (long j = i + 1, k = nums.size() - 1; j < k;) {
            int b = nums[j];
            int c = nums[k];
            int value = a + b + c;
            if (value == 0) {
                result.push_back(vector<int>({a, b, c}));
                while (j<k && b == nums[j])
                    j++;
                while (j<k && c == nums[k])
                    k--;
            } else if (value > 0) {
                k--;
            } else {
                j++;
            }
        }
    }
    return result;      
}

