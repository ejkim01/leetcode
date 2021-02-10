/*
In a given integer array A, we must move every element of A to either list B or list C. (B and C initially start empty.)
Return true if and only if after such a move, it is possible that the average value of B is equal to the average value of C, and B and C are both non-empty.
Example :
Input: 
[1,2,3,4,5,6,7,8]
Output: true
Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have the average of 4.5.

Note:
The length of A will be in the range [1, 30].
A[i] will be in the range of [0, 10000].
*/

bool splitArraySameAverage(vector<int>& A) {
    int n = A.size(), m = n/2;
    int sum = 0;
    for (int num: A) sum += num;

    bool found = 0;
    for (int i=m; i>0; i--)
        if (sum*i%n==0) {
            found = 1;
            m = i;
            break;
        }
    if (!found) return false;

    vector<unordered_set<int>> dp(m+1);
    dp[0].insert(0);
    for (int num: A) {
        for (int i=m; i>0; i--) {
            for (int k: dp[i-1])
                dp[i].insert(k+num);
            if (sum*i%n==0 && dp[i].find(sum*i/n)!=dp[i].end()) return true;
        }
    }    
    return false;
}