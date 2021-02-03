/*
Given a string S, return the number of substrings of length K with no repeated characters.
 
Example 1:
Input: S = "havefunonleetcode", K = 5
Output: 6
Explanation: 
There are 6 substrings they are : 'havef','avefu','vefun','efuno','etcod','tcode'.

Example 2:
Input: S = "home", K = 5
Output: 0
Explanation: 
Notice K can be larger than the length of S. In this case is not possible to find any substring.
 
Note:
1 <= S.length <= 10^4
All characters of S are lowercase English letters.
1 <= K <= 10^4
*/

int numKLenSubstrNoRepeats(string S, int K) {
    unordered_set<int> cur;
    int res = 0;
    int left=0, right=0;
    while (right<S.length()) {
        while (cur.count(S[right]))
            cur.erase(S[left++]);
        cur.insert(S[right]);
        res += right - left + 1 >= K;
        right++;
    }
    return res;
}
