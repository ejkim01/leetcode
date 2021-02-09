/*
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
*/

void moveZeroes(vector<int>& nums) {
    for (int i = 0, j = 0; j < nums.size(); ++j) {
        if (nums[j]) {
            swap(nums[i++], nums[j]);
        }
    }   
}