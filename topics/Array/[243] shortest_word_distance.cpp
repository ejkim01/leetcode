/*
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.
*/

int shortestDistance(vector<string>& words, string word1, string word2) {
    int p1 = -1, p2 = -1, res = INT_MAX;
    for (int i = 0; i < words.size(); ++i) {
        if (words[i] == word1) p1 = i;
        else if (words[i] == word2) p2 = i;
        if (p1 != -1 && p2 != -1) res = min(res, abs(p1 - p2));
    }
    return res;
}