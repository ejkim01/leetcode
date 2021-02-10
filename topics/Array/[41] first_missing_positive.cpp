/*
Given an unsorted integer array, find the smallest missing positive integer.
Example 1:
Input: [1,2,0]
Output: 3

Example 2:
Input: [3,4,-1,1]
Output: 2

Example 3:
Input: [7,8,9,11,12]
Output: 1

Note:
Your algorithm should run in O(n) time and uses constant extra space.

https://www.youtube.com/watch?v=9SnkdYXNIzM

The missing number should be in the range of 1 and nums.size()+1
*/

int firstMissingPositive(vector<int>& nums) {
    if (nums.size()==0) return 1;
    
    bool containsOne = false;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i]==1) {
            containsOne = true;
        } else if (nums[i]<=0 || nums[i]>nums.size()) {
            nums[i] = 1;
        }
    }
    if (containsOne==false) return 1;
    
    for (int i=0; i<nums.size(); i++) {
        int index = abs(nums[i])-1;
        if (nums[index]>0) nums[index] *= -1;
    }
    for (int i=0; i<nums.size(); i++) {
        if (nums[i]>0) return i+1;
    }
    return nums.size()+1;
}
