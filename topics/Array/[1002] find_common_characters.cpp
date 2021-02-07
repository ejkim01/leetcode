/*
Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.
You may return the answer in any order.
 
Example 1:
Input: ["bella","label","roller"]
Output: ["e","l","l"]
 
Example 2:
Input: ["cool","lock","cook"]
Output: ["c","o"]
 
Note:
1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter
*/

vector<string> commonChars(vector<string>& A) {
    vector<int> min_count(26, INT_MAX);
    for (const string& a : A) {
        vector<int> count(26, 0);
        for (const char ch : a)
            ++count[ch - 'a'];
        for (int i = 0; i < 26; ++i)
            min_count[i] = min(min_count[i], count[i]);
    }
    vector<string> ans;
    for (int i = 0; i < 26; ++i) {
        if (min_count[i] == INT_MAX) continue;
        for (int j = 0; j < min_count[i]; ++j)
            ans.push_back(string(1, 'a' + i));
    }
    return ans;
}
