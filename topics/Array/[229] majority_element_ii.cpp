/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Note: The algorithm should run in linear time and in O(1) space.
Example 1:
Input: [3,2,3]
Output: [3]
Example 2:
Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/

vector<int> majorityElement(vector<int>& nums) {
    vector<int> res;
    int m = 0, n = 0, m_count = 0, n_count = 0;
    for (auto &a : nums) {
        if (a == m) ++m_count;
        else if (a ==n) ++n_count;
        else if (m_count == 0) m = a, m_count = 1;
        else if (n_count == 0) n = a, n_count = 1;
        else --m_count, --n_count;
    }
    m_count = n_count = 0;
    for (auto &a : nums) {
        if (a == m) ++m_count;
        else if (a == n) ++n_count;
    }
    if (m_count > nums.size() / 3) res.push_back(m);
    if (n_count > nums.size() / 3) res.push_back(n);
    return res;
}