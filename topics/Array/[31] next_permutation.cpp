/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place and use only constant extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
 
void nextPermutation(vector<int>& nums) {
    int left = 0;
    for (left = nums.size()-1; left>0; left--) {
        if (nums[left-1]<nums[left]) break;
    }
    if (left==0) return reverse(nums.begin(), nums.end());
    left--;
    for (int right = nums.size()-1; right>left; right--) {
        if (nums[right]>nums[left]) {
            swap(nums[left], nums[right]);
            break;
        }
    }
    return sort(nums.begin()+left+1, nums.end());
}
