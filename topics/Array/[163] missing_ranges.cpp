/*
Given a sorted integer array nums, where the range of elements are in the inclusive range[lower, upper], return its missing ranges.
Example:
Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]
*/

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> res;
    for (int num : nums) {
        if (num > lower) res.push_back(to_string(lower) + (num - 1 > lower ? ("->" + to_string(num - 1)) : ""));
        if (num == upper) return res;
        lower = num + 1;
    }
    if (lower <= upper) res.push_back(to_string(lower) + (upper > lower ? ("->" + to_string(upper)) : ""));
    return res;
}