/*
The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.
Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.
Input: nums = [1,2,2,4]
Output: [2,3]
*/

vector<int> findErrorNums(vector<int>& nums) {
    vector<int> res(2, 0), cnt(nums.size(), 0);
    for (int num : nums) ++cnt[num - 1];
    for (int i = 0; i < cnt.size(); ++i) {
        if (res[0] != 0 && res[1] != 0) return res;
        if (cnt[i] == 2) res[0] = i + 1;
        else if (cnt[i] == 0) res[1] = i + 1;
    }
    return res;
}