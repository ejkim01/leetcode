/*
Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.
You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.
 
Example 1:
Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.

Example 2:
Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
 
Example 3:
Input: name = "leelee", typed = "lleeelee"
Output: true
 
Example 4:
Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.
 
 
Note:
name.length <= 1000
typed.length <= 1000
The characters of name and typed are lowercase letters.
*/

bool isLongPressedName(string name, string typed) {
    int i = 0, j = 0, m = name.size(), n = typed.size();
    while (i < m || j < n) {
        int start1 = i, start2 = j;
        while (i < m - 1 && name[i] == name[i + 1]) ++i;
        while (j < n - 1 && typed[j] == typed[j + 1]) ++j;
        if (j - start2 + 1 < i - start1 + 1) return false;
        ++i; ++j;
    }
    return i == m && j == n;
}
