/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
Note:
Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2
*/

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> res;
    int start = 0;
    int end = numbers.size()-1;
    
    while (start<end) {
        if (numbers[start]+ numbers[end] > target)            
            end--;
        else if (numbers[start] + numbers[end] < target)
            start++;
        else {
            res.push_back(start+1);
            res.push_back(end+1);
            break;
        }
            
    }
    return res;
}
