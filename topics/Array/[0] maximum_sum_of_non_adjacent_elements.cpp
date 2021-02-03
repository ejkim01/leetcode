// This question is not in Leetcode, but it's a variant of "House Robber"

/*
Examples :
Input : arr[] = {5, 5, 10, 100, 10, 5}
Output : 110

Input : arr[] = {1, 2, 3}
Output : 4

Input : arr[] = {1, 20, 3}
Output : 20
*/

int maxNonAdjacent(vector<int> nums) {
    int maxWithCurr = nums[0];
    int maxWithoutCurr = 0;
    int maxSoFar = 0;

    for (int i=1; i<nums.size(); i++) {
        maxSoFar = max(maxWithoutCurr+nums[i], maxWithCurr);
        maxWithoutCurr = maxWithCurr;
        maxWithCurr = maxSoFar;
    }
    return maxSoFar;
}

================================================================

int sumNonAdjacent(vector<int> nums) {
    if (nums.size() == 0) return 0;

    int curr1 = 0;
    int curr2 = nums[0];
    int curr = 0;

    for (int i = 1; i < nums.size(); i++) {
        curr = max(curr1, curr2);
        curr2 = curr1 + nums[i];
        curr1 = curr;
    }
    return max(curr1, curr2);
}



