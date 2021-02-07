/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

int maxProduct(vector<int>& nums) {
    int minVal = nums[0]; 
    int maxVal = nums[0]; 
    int maxProduct = nums[0]; 

    for (int i = 1; i < nums.size(); i++) { 
        if (nums[i] < 0) 
            swap(maxVal, minVal); 
        maxVal = max(nums[i], maxVal * nums[i]); 
        minVal = min(nums[i], minVal * nums[i]); 

        maxProduct = max(maxProduct, maxVal); 
    } 
    return maxProduct; 
}
