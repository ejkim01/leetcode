/*
Given a string s that consists of only uppercase English letters, you can perform at most k operations on that string.
In one operation, you can choose any character of the string and change it to any other uppercase English character.
Find the length of the longest sub-string containing all repeating letters you can get after performing the above operations.
Note:
Both the string's length and k will not exceed 104.
Example 1:
Input:
s = "ABAB", k = 2

Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.

 
Example 2:
Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
*/

int characterReplacement(string s, int k) {
    int left = 0;
    int right = 0;
    int res = 0;
    int maxCnt = 0;
    int len = s.length();
    unordered_map<char, int> m;

    while (right < len) {
        maxCnt = max(maxCnt, ++m[s[right]]);
        while (right-left+1 - maxCnt > k) {
            --m[s[left++]];
        }
        res = max(res, right - left + 1);
        right++;
    }
    return res;
}
