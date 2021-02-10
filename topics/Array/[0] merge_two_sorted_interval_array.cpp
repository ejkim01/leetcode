/*
This problem is not in Leetcode

You have two sorted arrays, where each element is an interval. Now, merge the two array, overlapping intervals can be merged as a single one. 

Input : 
List 1 [1,2] , [3,9] 
List 2 [4,5], [8, 10], [11,12] 

Output:
[1,2], [3,10], [11,12]
*/

vector<vector<int>> mergeTwoArrays(vector<vector<int>> A, vector<vector<int>> B) {
	int pa = 0, pb = 0;
	vector<vector<int>> res;

	if (A[pa][0] < B[pb][0]) {
		res.push_back(A[pa++]);
	}
	else {
		res.push_back(B[pb++]);
	}

	while (pa < A.size()) {
		if (res.back()[1] < A[pa][0]) {
			res.push_back(A[pa++]);
		}
		else {
			res.back()[0] = min(res.back()[0], A[pa][0]);
			res.back()[1] = max(res.back()[1], A[pa][1]);
			pa++;
		}
	}
	while (pb < B.size()) {
		if (res.back()[1] < B[pb][0]) {
			res.push_back(B[pb++]);
		}
		else {
			res.back()[0] = min(res.back()[0], B[pb][0]);
			res.back()[1] = max(res.back()[1], B[pb][1]);
			pb++;
		}
	}
	return res;
}
